/*
 * main.cpp
 *
 *  Created on: 2020/04/25
 *      Author: aslab
 */

#include <Knight.h>
#include <Warrior.h>
#include <Archer.h>
#include <Trol.h>

#include "Battle.h"
#include "Mainwindow.h"

#include <vector>

#include <boost/shared_ptr.hpp>

#include <QApplication>
#include <QObject>


int main(int argc, char* argv[]){

	QApplication app(argc, argv);
	Mainwindow *win = new Mainwindow();
	win->show();

	Battle *battle = new Battle();

	QObject::connect(win, SIGNAL(RotateSignal(bool)), battle, SLOT(handleReadyflag(bool)));
	QObject::connect(win, SIGNAL(RunSignal(bool)), battle, SLOT(handleRunflag(bool)));

	QObject::connect(battle, SIGNAL(ReadySignal(bool)), win, SLOT(handleReady(bool)));
	QObject::connect(battle, SIGNAL(HPSignal(int,int,int)), win, SLOT(handleHP(int,int,int)));


	boost::shared_ptr<Character> k1 (new Knight(0,0,30,10,8.0f,3,5));
	boost::shared_ptr<Character> k2 (new Knight(0,1,30,10,8.1f,3,5));
	boost::shared_ptr<Character> k3 (new Knight(0,2,30,10,8.2f,3,5));
	boost::shared_ptr<Character> a1 (new Archer(1,1,20,3,9.0f,15));

	std::vector< boost::shared_ptr<Character> > unit_list;
	unit_list.push_back(k1);
	unit_list.push_back(k2);
	unit_list.push_back(k3);
	unit_list.push_back(a1);


	boost::shared_ptr<Enemy> t1 (new Trol(60, 10, 3.0f, 3, 5));

	battle->start(unit_list, t1);

	return app.exec();;

}


