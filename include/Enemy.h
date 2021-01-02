/*
 * Enemy.h
 *
 *  Created on: 2020/04/26
 *      Author: aslab
 */

#ifndef INCLUDE_ENEMY_H_
#define INCLUDE_ENEMY_H_

#include "Unit.h"


class Enemy: public Unit {
public:
	Enemy();
	Enemy(const int hp,	const int attack, const float speed);
	virtual ~Enemy();

	virtual int attack();

	virtual void damage(const int damage);

	int get_buf();

	int get_def();

};

#endif /* INCLUDE_ENEMY_H_ */
