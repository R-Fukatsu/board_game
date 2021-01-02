/*
 * Battle.cpp
 *
 *  Created on: 2020/04/25
 *      Author: aslab
 */

#include "Battle.h"

#include <iostream>
#include <cstdlib>
#include <string>
#include <typeinfo>
#include <unistd.h>
#include <unistd.h>


using namespace std;


Battle::Battle() {

	_board = Board();
	_get_rotate = false;
	_rotate_state = Empty;

}

Battle::~Battle() {}

void Battle::init_phase(){

	//TODO: when enemy's hp is 0, exit

	std::vector< boost::shared_ptr<Unit> > order;

	if(_board.get_enemy_hp() > 0){

		cout << _board.get_enemy_hp() << endl;

		order.clear();
		cout << "get order" << endl;
		_board.get_action_order(order);

		cout << "attack" << endl;
		attack_phase(order);

	} else {

		cout << "battle end" << endl;
		exit(0);

	}

}

void Battle::start(std::vector< boost::shared_ptr<Character> >& unit_list,
					boost::shared_ptr<Enemy> enemy){

	cout << "set characters" << endl;
	for(size_t i=0; i<unit_list.size(); i++){
		_board.set_character(unit_list[i]);
	}

	cout << "set enemies\n" << endl;
	_board.set_enemy(enemy);

	show_hp();

}

void Battle::handleReadyflag(bool flag){

	std::cout << "get ready" << std::endl;

	if(flag){
		_rotate_state = Rotate;
	}else{
		_rotate_state = Stay;
	}

	_get_rotate = true;

	rotate_phase();

}

void Battle::handleRunflag(bool flag){

	if(flag){
		init_phase();
	}

}

void Battle::attack_phase(std::vector< boost::shared_ptr<Unit> >& order){

	for(size_t i=0; i<order.size(); i++){

		if( order[i]->is_character() ){

			while(order[i]->get_multi() >= 0){
				char_attack(order[i]);
			}

		}else {

			while(order[i]->get_multi() >= 0){
				enemy_attack(order[i]);
			}

		}
	}

	show_hp();

	emit ReadySignal(true);

}

void Battle::char_attack(boost::shared_ptr<Unit>& unit){

	int damage;
	int buf = 0;
	boost::shared_ptr<Unit> support_unit(new Unit);

	if(_board.get_rear(unit->get_x(), unit->get_y(), support_unit)){
		buf = _board.get_support(support_unit, &Unit::get_buf);
	}else{
		buf = 0;
	}

	damage = _board.get_attack(unit) + buf;
	cout << "char" << damage << endl;
	_board.attack_enemy(damage);

}

void Battle::enemy_attack(boost::shared_ptr<Unit>& unit){

	int target;
	int damage;
	int def = 0;
	boost::shared_ptr<Unit> support_unit(new Unit);

	damage = unit->attack();
	target = _board.select_target();

	if(_board.get_rear(target, _board.get_cur_target_row(), support_unit)){
		def = _board.get_support(support_unit, &Unit::get_def);
	}else{
		def = 0;
	}

	cout << "enemy" << damage-def << endl;
	_board.attack_character(damage-def, target);

}

void Battle::rotate_phase(){

	if(_rotate_state == Empty){

		try{
			throw "invaild rotate state";
		}catch(char* error){
			cerr << error << endl;
			exit(EXIT_FAILURE);
		}

	}else if(_rotate_state == Rotate){

		_board.reset_init_support();
		_board.rotate_row();

	}

	_rotate_state = Empty;
	_get_rotate = false;

	cout << "heal" << endl;
	heal_phase();

}

void Battle::heal_phase(){

	_board.heal_all();

	init_phase();
}

void Battle::show_hp(){

	emit HPSignal(-1, 0, 0);

	emit HPSignal(_board.get_enemy_hp(), -1, -1);

	int tmp;
	for(int i=0; i<MAX_COLUMN; i++){
		for(int j=0; j<MAX_ROW; j++){

			tmp = _board.get_character_hp(i,j);

			if(tmp<0) continue;

			emit HPSignal(tmp, (3-_board.get_cur_row()+j)%3, i);

		}
	}

}
