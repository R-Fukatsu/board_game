/*
 * Archer.cpp
 *
 *  Created on: 2020/04/28
 *      Author: aslab
 */

#include "/home/aslab/eclipse_ws/c++_study2/include/Archer.h"

Archer::Archer():
	Character()
{}

Archer::Archer(const int x, const int y, const int hp,
		const int attack, const float speed,
		const int indirect_attack):
		Character(x, y, hp, attack, speed)
{
	_indirect_attack=indirect_attack;
}


Archer::~Archer() {}

