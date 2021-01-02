/*
 * Mainwindow.cpp
 *
 *  Created on: 2020/05/03
 *      Author: aslab
 */

#include "Mainwindow.h"

#include <QGraphicsView>
#include <QStatusBar>
#include <QFont>

#include <iostream>
#include <cstdlib>
#include <string>


Mainwindow::Mainwindow(QWidget *parent) :
    QMainWindow(parent)
{

	setGeometry(0, 0, 1200, 1000);

	scene = new QGraphicsScene(100, 100, 800, 800);
	scene -> addRect(QRectF(350,150,100,100),QPen(),QBrush());


	scene -> addRect(QRectF(200,600,100,100),QPen(),QBrush());
	scene -> addRect(QRectF(300,600,100,100),QPen(),QBrush());
	scene -> addRect(QRectF(400,600,100,100),QPen(),QBrush());
	scene -> addRect(QRectF(500,600,100,100),QPen(),QBrush());

	scene -> addRect(QRectF(200,500,100,100),QPen(),QBrush());
	scene -> addRect(QRectF(300,500,100,100),QPen(),QBrush());
	scene -> addRect(QRectF(400,500,100,100),QPen(),QBrush());
	scene -> addRect(QRectF(500,500,100,100),QPen(),QBrush());

	scene -> addRect(QRectF(200,400,100,100),QPen(),QBrush());
	scene -> addRect(QRectF(300,400,100,100),QPen(),QBrush());
	scene -> addRect(QRectF(400,400,100,100),QPen(),QBrush());
	scene -> addRect(QRectF(500,400,100,100),QPen(),QBrush());


	text_list = QVector<QGraphicsTextItem*>(7);
	text_list[0] = item0;
	text_list[1] = item1;
	text_list[2] = item2;
	text_list[3] = item3;
	text_list[4] = item4;
	text_list[5] = item5;
	text_list[6] = item6;

	_text_counter = 0;


	view = new QGraphicsView(scene);
	setCentralWidget(view);

	rotate_button = new QPushButton("Rotate", this);
	rotate_button -> setGeometry(QRect(QPoint(1000,100), QSize(150,50)));
	connect(rotate_button, SIGNAL(released()), this, SLOT(handleRButton()));

	stay_button = new QPushButton("Stay", this);
	stay_button -> setGeometry(QRect(QPoint(1000,200), QSize(150,50)));
	connect(stay_button, SIGNAL(released()), this, SLOT(handleSButton()));

	run_button = new QPushButton("Run", this);
	run_button -> setGeometry(QRect(QPoint(1000,300), QSize(150,50)));
	connect(run_button, SIGNAL(released()), this, SLOT(handleRunButton()));

	statusBar()->showMessage("Process...");

}

Mainwindow::~Mainwindow() {

}

void Mainwindow::handleSButton(){
	statusBar()->showMessage("Process...");
	emit RotateSignal(false);
}

void Mainwindow::handleRButton(){
	statusBar()->showMessage("Process...");
	emit RotateSignal(true);
}

void Mainwindow::handleRunButton(){
	std::cout << "get run" << std::endl;
	emit RunSignal(true);
}

void Mainwindow::handleReady(bool flag){
	std::cout << "handle ready" << std::endl;
	statusBar()->showMessage("Rotate or Stay [r/s]");
}

void Mainwindow::handleHP(int hp, int row, int col){

	if(hp < 0){

		for(int i=0; i<_text_counter; i++){
			scene -> removeItem(text_list[i]);
		}
		_text_counter = 0;
		return;
	}

	// include the number of enemy
	if(_text_counter == 8){
		try{
			throw "more than maximum number of units";
		}catch(char* error){
			std::cerr << error << std::endl;
			exit(EXIT_FAILURE);
		}
	}


	std::string str;
	if((row<0) && (col<0)){

		str = std::to_string(hp);

		text_list[_text_counter] = scene -> addText(str.c_str());
		text_list[_text_counter] -> setFont(QFont("Times", 30, QFont::Bold));
		text_list[_text_counter] -> setPos(375, 175);

		_text_counter++;
		return;
	}

	str = std::to_string(hp);
	text_list[_text_counter] = scene -> addText(str.c_str());
	text_list[_text_counter] -> setFont(QFont("Times", 30, QFont::Bold));
	text_list[_text_counter] -> setPos(225+col*100, 425+row*100);

	_text_counter++;

}
