/*
 * Warrior.h
 *
 *  Created on: 2020/04/26
 *      Author: aslab
 */

#ifndef INCLUDE_WARRIOR_H_
#define INCLUDE_WARRIOR_H_

#include "Character.h"

class Warrior: public Character {
public:
	Warrior();
	Warrior(const int x, const int y, const int hp,
			const int attack, const float speed);
	virtual ~Warrior();
};

#endif /* INCLUDE_WARRIOR_H_ */
