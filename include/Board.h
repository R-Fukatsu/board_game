/*
 * Board.h
 *
 *  Created on: 2020/04/26
 *      Author: aslab
 */

#ifndef INCLUDE_BOARD_H_
#define INCLUDE_BOARD_H_

#include <Enemy.h>
#include <Character.h>

#include <vector>

#include <boost/shared_ptr.hpp>

#define MAX_COLUMN 4
#define MAX_ROW 3


typedef int (Unit::*Sfunc)();

class Board {
public:

	Board();
	virtual ~Board();

	void set_character(boost::shared_ptr<Unit> unit);

	void set_enemy(boost::shared_ptr<Unit> enemy);

	int get_character_hp(const int x, const int y);

	int get_enemy_hp();

	void get_action_order(std::vector< boost::shared_ptr<Unit> >& list);

	void rotate_row();

	int get_attack(boost::shared_ptr<Unit> unit);

	bool get_rear(const int x, const int y, boost::shared_ptr<Unit>& unit);

	int get_support(boost::shared_ptr<Unit> unit, Sfunc func);

	void attack_enemy(const int damage);

	void attack_character(const int damage, const int target);

	int select_target(const int count=0);

	int get_cur_row();

	int get_cur_target_row();

	void reset_init_support();

	void heal_all();


private:

	std::vector< boost::shared_ptr<Unit> > row0,row1,row2;
	std::vector< std::vector< boost::shared_ptr<Unit> > > all;

	boost::shared_ptr<Unit> _enemy;

	int _cur_row;
	int _cur_target_row;

	boost::shared_ptr<Unit> empty;

};

#endif /* INCLUDE_BOARD_H_ */
