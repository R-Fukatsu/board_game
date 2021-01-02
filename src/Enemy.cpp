/*
 * Enemy.cpp
 *
 *  Created on: 2020/04/26
 *      Author: aslab
 */

#include "/home/aslab/eclipse_ws/c++_study2/include/Enemy.h"

Enemy::Enemy()
{
	_max_hp=0;
	_hp=0;
	_attack=0;
	_speed=0.0f;

	_heal=-1;
	_buf=-1;
	_defence=-1;

	_place=false;

	_isE=false;
}

Enemy::Enemy(const int hp,	const int attack, const float speed)
{
	_max_hp=hp;
	_hp=hp;
	_attack=attack;
	_speed=speed;

	_heal=-1;
	_buf=-1;
	_defence=-1;

	_place=true;

	_isE=true;
}

Enemy::~Enemy() {}

int Enemy::attack(){

	if(_init_buf){

		_init_buf = false;

		if(_buf<0){
			return _attack;
		}else{
			return _attack+_buf;
		}

	}else{

		return _attack;

	}

}

void Enemy::damage(const int damage){

	if(_init_def){

		_init_def = false;

		if(damage > _defence){
			_hp -= (damage - _defence);
		}

	}else{

		_hp -= damage;

	}
}
