/*
 * Unit.h
 *
 *  Created on: 2020/04/27
 *      Author: aslab
 */

#ifndef INCLUDE_UNIT_H_
#define INCLUDE_UNIT_H_

class Unit {
public:
	Unit();
	virtual ~Unit();

	virtual int attack();

	int indirect_attack();

	virtual void damage(const int damage);

	int get_x();

	int get_y();

	int get_hp();

	float get_speed();

	void heal(const int heal);

	int get_buf();

	int get_def();

	void heal();

	void reset_init();

	int get_multi();

	bool placed();

	bool is_character();


protected:

	int _max_hp;
	int _hp;
	int _x,_y;
	float _speed;
	int _attack;
	int _heal;

	int _buf,_defence;
	bool _init_def,_init_buf;

	int _indirect_attack;

	int _multi_atk,_multi_cur;

	bool _place;

	bool _isC,_isE;
};

#endif /* INCLUDE_UNIT_H_ */
