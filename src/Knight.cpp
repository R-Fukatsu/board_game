/*
 * Knight.cpp
 *
 *  Created on: 2020/04/26
 *      Author: aslab
 */

#include "Knight.h"

Knight::Knight():
	Character()
{}

Knight::Knight(const int x, const int y, const int hp,
		const int attack, const float speed,
		const int heal, const int defence):
		Character(x, y, hp, attack, speed)
{
	_heal=heal;
	_defence=defence;
}

Knight::~Knight() {
}

