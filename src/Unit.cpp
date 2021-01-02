/*
 * Unit.cpp
 *
 *  Created on: 2020/04/27
 *      Author: aslab
 */

#include "/home/aslab/eclipse_ws/c++_study2/include/Unit.h"

#include <cstdlib>
#include <iostream>

Unit::Unit() {
	_max_hp=-1;
	_hp=-1;
	_x=0;
	_y=0;
	_speed=0.0f;
	_attack=0;
	_heal=-1;

	_buf=-1;
	_defence=-1;
	_init_buf=true;
	_init_def=true;

	_indirect_attack=-1;

	_multi_atk=1;
	_multi_cur=1;

	_place=false;

	_isC=false;
	_isE=false;
}

Unit::~Unit() {
}

int Unit::attack(){
	return _attack;
}

int Unit::indirect_attack(){
	return _indirect_attack;
}

void Unit::damage(const int damage){
	if(damage<0){
		_hp -= 0;
	}else{
		_hp -= damage;
	}
}

int Unit::get_x(){
	return _x;
}

int Unit::get_y(){
	return _y;
}

int Unit::get_hp(){
	return _hp;
}

float Unit::get_speed(){
	return _speed;
}

void Unit::heal(const int heal){
	_hp += heal;
}

int Unit::get_buf(){
	if(_init_buf){
		_init_buf = false;
		return _buf;
	}else{
		return -1;
	}
}

int Unit::get_def(){
	if(_init_def){
		_init_def = false;
		return _defence;
	}else{
		return -1;
	}
}

void Unit::heal(){
	if(_heal > 0 && _max_hp >= _hp+_heal){
		_hp += _heal;
	}
}

void Unit::reset_init(){
	_init_buf = true;
	_init_def = true;
}

int Unit::get_multi(){
	if(_multi_cur==0){
		_multi_cur = _multi_atk;
		return -1;
	}else{
		_multi_cur -= 1;
		return _multi_cur;
	}
}


bool Unit::placed(){
	return _place;
}

bool Unit::is_character(){
	if(_isC && !_isE){
		return true;
	} else if(!_isC && _isE){
		return false;
	}else{
		try{
			throw "invaild unit";
		}catch(char* error){
			std::cerr << error << std::endl;
			std::exit(EXIT_FAILURE);
			return false;
		}
	}
}
