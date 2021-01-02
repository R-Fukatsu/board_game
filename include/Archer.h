/*
 * Archer.h
 *
 *  Created on: 2020/04/28
 *      Author: aslab
 */

#ifndef INCLUDE_ARCHER_H_
#define INCLUDE_ARCHER_H_

#include "Character.h"

class Archer: public Character {
public:
	Archer();
	Archer(const int x, const int y, const int hp,
			const int attack, const float speed,
			const int indirect_attack);
	virtual ~Archer();
};

#endif /* INCLUDE_ARCHER_H_ */
