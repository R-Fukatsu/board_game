/*
 * Trol.cpp
 *
 *  Created on: 2020/04/26
 *      Author: aslab
 */

#include "Trol.h"

Trol::Trol():
	Enemy()
{
	_init_def = false;
}

Trol::Trol(const int hp, const int attack, const float speed,
		const int heal, const int defence):
		Enemy(hp, attack, speed)
{
	_heal=heal;
	_defence=defence;
}

Trol::~Trol() {}

