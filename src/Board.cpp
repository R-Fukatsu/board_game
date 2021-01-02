/*
 * Board.cpp
 *
 *  Created on: 2020/04/26
 *      Author: aslab
 */

#include "Board.h"

#include <iostream>
#include <cstdlib>
#include <random>
#include <cmath>


using namespace std;

Board::Board() {

	empty = boost::shared_ptr<Unit>(new Unit);

	for(int i=0; i<MAX_COLUMN; i++){
		row0.push_back(empty);
		row1.push_back(empty);
		row2.push_back(empty);
	}

	//row0 = std::vector< boost::shared_ptr<Unit> > (MAX_COLUMN);
	all.push_back(row0);

	//row1 = std::vector< boost::shared_ptr<Unit> > (MAX_COLUMN);
	all.push_back(row1);

	//row2 = std::vector< boost::shared_ptr<Unit> > (MAX_COLUMN);
	all.push_back(row2);

	_enemy = boost::shared_ptr<Unit>(new Enemy);

	_cur_row = 0;
	_cur_target_row = 0;
}

Board::~Board() {}

void Board::set_character(boost::shared_ptr<Unit> unit){

	int x = unit->get_x();
	int y = unit->get_y();

	try{
		if(x>3) throw "invalid x";
		if(y>2) throw "invalid y";
	} catch(const char* error) {
		cerr << error << endl;
		exit(EXIT_FAILURE);
	}

	all[y][x] = unit;

}

void Board::set_enemy(boost::shared_ptr<Unit> enemy){
	_enemy = enemy;
}

int Board::get_character_hp(const int x, const int y){
	return all[y][x]->get_hp();
}

int Board::get_enemy_hp(){
	return _enemy->get_hp();
}

void Board::get_action_order(std::vector< boost::shared_ptr<Unit> >& list){

	list.push_back(_enemy);

	for(int i=0; i<MAX_COLUMN; i++){

		if(all[_cur_row][i]->placed()){

			for(size_t j=0; j<list.size(); j++){

				if(all[_cur_row][i]->get_speed() > list[j]->get_speed()){
					list.insert(list.begin()+j, all[_cur_row][i]);
					break;
				}else{
					list.insert(list.begin()+j+1, all[_cur_row][i]);
					break;
				}

			}

		}else{

			if(all[(_cur_row+1)%3][i]->placed() &&
					(all[(_cur_row+1)%3][i]->indirect_attack() > 0) ){

				for(size_t j=0; j<list.size(); j++){

					if(all[_cur_row][i]->get_speed() > list[j]->get_speed()){
						list.insert(list.begin()+j, all[(_cur_row+1)%3][i]);
						break;
					}else{
						list.insert(list.begin()+j+1, all[(_cur_row+1)%3][i]);
						break;
					}

				}

			}

		}

	}

}

void Board::rotate_row(){
	_cur_row += 1;
	_cur_row %= 3;

	_cur_target_row = _cur_row;
}

int Board::get_attack(boost::shared_ptr<Unit> unit){

	if(unit->get_y() == _cur_row){

		return unit->attack();

	}else if(unit->get_y() == (_cur_row+1)%3){

		int result = unit->indirect_attack();
		if(result>0){
			return result;
		}else{
			try{
				throw "invaild indirect attack";
			}catch(char* error){
				cerr << error << endl;
				exit(EXIT_FAILURE);
			}
		}

	}else{

		try{
			throw "invaild attacker";
		}catch(char* error){
			cerr << error << endl;
			exit(EXIT_FAILURE);
		}

	}
}

bool Board::get_rear(const int target_x, const int target_y, boost::shared_ptr<Unit>& unit){

	int x = all[target_y][target_x]->get_x();
	int y = all[target_y][target_x]->get_y();
	int rear = (y + 1)%3;

	if(y != _cur_row){
		return false;
	}

	if(all[rear][x]->placed()){
		unit = all[rear][x];
		return true;
	}else{
		return false;
	}

}

int Board::get_support(boost::shared_ptr<Unit> unit, Sfunc func){

	int support = (unit.get()->*func)();

	if(support < 0){
		return 0;
	}else{
		return support;
	}

}

void Board::attack_enemy(const int damage){
	_enemy->damage(damage);
}

void Board::attack_character(const int damage, const int target){
	all[_cur_target_row][target]->damage(damage);
	_cur_target_row = _cur_row;
}


int Board::select_target(const int count){

	if(count == 3){
		try{
			throw "no character on the board";
		} catch(const char* error) {
			cerr << error << endl;
			exit(EXIT_FAILURE);
		}
	}

	int unit_num = 0;
	std::vector<int> unit_idx;
	for(size_t i=0; i<MAX_COLUMN; i++){
		if(all[_cur_target_row][i]->placed()){
			unit_num++;
			unit_idx.push_back(i);
		}
	}

	if(unit_num == 0){
		_cur_target_row += 1;
		_cur_target_row %= 3;

		return select_target(count+1);
	}


	std::random_device seed_gen;
	std::default_random_engine engine(seed_gen());
	std::uniform_real_distribution<> dist(0.0, 1.0);

	double rnd = dist(engine);
	int target = (int)floor(rnd*(double)unit_num);

	return unit_idx[target];

}

int Board::get_cur_row(){
	return _cur_row;
}

int Board::get_cur_target_row(){
	return _cur_target_row;
}

void Board::reset_init_support(){

	for(int i=0; i<MAX_COLUMN; i++){
		for(int j=0; j<MAX_ROW; j++){

			all[j][i]->reset_init();

		}
	}

	_enemy->reset_init();

}

void Board::heal_all(){

	_enemy->heal();

	int end_row  = (_cur_row+2)%3;
	for(int i=0; i<MAX_COLUMN; i++){

		if(all[end_row][i]->placed()){
			all[end_row][i]->heal();
		}

	}

}

