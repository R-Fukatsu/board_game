/*
 * Character.cpp
 *
 *  Created on: 2020/04/25
 *      Author: aslab
 */

#include "Character.h"

Character::Character() {
	_x=0;
	_y=0;

	_max_hp=0;
	_hp=0;
	_attack=0;
	_indirect_attack=-1;
	_speed=0.0f;

	_heal=-1;
	_expand=false;
	_buf=-1;
	_defence=-1;

	_place=false;

	_isC=false;
}

Character::Character(const int x, const int y, const int hp,
					const int attack, const float speed) {
	_x=x;
	_y=y;

	_max_hp=hp;
	_hp=hp;
	_attack=attack;
	_indirect_attack=-1;
	_speed=speed;

	_heal=-1;
	_expand=false;
	_buf=-1;
	_defence=-1;

	_place=true;
	_isC=true;
}

Character::~Character() {}

int Character::attack(){
	return _attack;
}

void Character::damage(const int damage){
	if(damage<0){
		_hp -= 0;
	}else{
		_hp -= damage;
	}
}

void Character::rotate(){
	_y = (_y+1)%3;
}
