/*
 * Knight.h
 *
 *  Created on: 2020/04/26
 *      Author: aslab
 */

#ifndef INCLUDE_KNIGHT_H_
#define INCLUDE_KNIGHT_H_

#include "Character.h"

class Knight: public Character {
public:
	Knight();
	Knight(const int x, const int y, const int hp,
			const int attack, const float speed,
			const int heal, const int defence);
	virtual ~Knight();
};

#endif /* INCLUDE_KNIGHT_H_ */
