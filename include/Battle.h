/*
 * Battle.h
 *
 *  Created on: 2020/04/25
 *      Author: aslab
 */

#ifndef INCLUDE_BATTLE_H_
#define INCLUDE_BATTLE_H_

#include "Board.h"

#include <QObject>
#include <QThread>

#include <vector>


class Battle:
	public QObject
{

	Q_OBJECT

public:
	Battle();
	virtual ~Battle();

	void start(std::vector< boost::shared_ptr<Character> >& unit_list,
				boost::shared_ptr<Enemy> enemy);

	void init_phase();


public slots:

	void handleReadyflag(bool flag);

	void handleRunflag(bool flag);


signals:

	void ReadySignal(bool flag);

	void HPSignal(int hp, int row, int col);


private:

	enum RotateFlag{
		Rotate,
		Stay,
		Empty
	};

	void attack_phase(std::vector< boost::shared_ptr<Unit> >& order);

	void char_attack(boost::shared_ptr<Unit>& unit);

	void enemy_attack(boost::shared_ptr<Unit>& unit);

	void rotate_phase();

	void heal_phase();

	void show_hp();


	Board _board;

	bool _get_rotate;
	RotateFlag _rotate_state;

};

#endif /* INCLUDE_BATTLE_H_ */
