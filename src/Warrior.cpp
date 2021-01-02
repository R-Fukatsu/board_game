/*
 * Warrior.cpp
 *
 *  Created on: 2020/04/26
 *      Author: aslab
 */

#include "Warrior.h"

Warrior::Warrior() :
	Character()
{}

Warrior::Warrior(const int x, const int y, const int hp,
		const int attack, const float speed):
		Character(x, y, hp, attack, speed)
{}

Warrior::~Warrior() {}

