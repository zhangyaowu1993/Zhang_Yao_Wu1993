#include "MyTimer.h"
#include <qtimer.h>
#include <qdebug.h>

MyTimer::MyTimer()
{
	QTimer *Timer = new QTimer( this );
	connect( Timer, SIGNAL( timeout() ), this, SLOT( Timer() ) );
	Timer->start( 1000 );
}


MyTimer::~MyTimer()
{

}

void MyTimer::Timer()
{
	qDebug() << "worked";
}


//加入一个基于QObject的类 然后在构造函数中建立Timer 在类中建立一个SLOT, connect这个slot和timer
//这个timer是基于this创建的 所以不需要析构 在this消灭的时候会自动delete timer; 所以只用管理this就可以