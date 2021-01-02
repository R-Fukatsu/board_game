/*
 * Mainwindow.h
 *
 *  Created on: 2020/05/03
 *      Author: aslab
 */

#ifndef INCLUDE_MAINWINDOW_H_
#define INCLUDE_MAINWINDOW_H_

#include <QMainWindow>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QVector>


class Mainwindow :
	public QMainWindow
{
    Q_OBJECT

public:

    Mainwindow(QWidget *parent = nullptr);
    ~Mainwindow();


public slots:

	void handleRButton();
	void handleSButton();
	void handleRunButton();

	void handleReady(bool flag);

	void handleHP(int hp, int row, int col);


signals:

	void RotateSignal(bool flag);

	void RunSignal(bool flag);


private:

	QGraphicsScene *scene;
	QGraphicsView *view;

    QPushButton *rotate_button;
    QPushButton *stay_button;
    QPushButton *run_button;

    QGraphicsTextItem *item0;
    QGraphicsTextItem *item1;
    QGraphicsTextItem *item2;
    QGraphicsTextItem *item3;
    QGraphicsTextItem *item4;
    QGraphicsTextItem *item5;
    QGraphicsTextItem *item6;

    QVector<QGraphicsTextItem*> text_list;

    int _text_counter;

};


#endif /* INCLUDE_MAINWINDOW_H_ */
