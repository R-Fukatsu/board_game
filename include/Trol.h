/*
 * Trol.h
 *
 *  Created on: 2020/04/26
 *      Author: aslab
 */

#ifndef INCLUDE_TROL_H_
#define INCLUDE_TROL_H_

#include "Enemy.h"

class Trol: public Enemy {
public:
	Trol();
	Trol(const int hp, const int attack, const float speed,
		const int heal, const int defence);
	virtual ~Trol();


private:

};

#endif /* INCLUDE_TROL_H_ */
