/*
 * Character.h
 *
 *  Created on: 2020/04/25
 *      Author: aslab
 */

#ifndef INCLUDE_CHARACTER_H_
#define INCLUDE_CHARACTER_H_

#include "Unit.h"

class Character: public Unit {
public:
	Character();
	Character(const int x, const int y, const int hp,
						const int attack, const float speed);
	virtual ~Character();

	virtual int attack();

	virtual void damage(const int damage);

	void rotate();


protected:

	bool _expand;

};

#endif /* INCLUDE_CHARACTER_H_ */
