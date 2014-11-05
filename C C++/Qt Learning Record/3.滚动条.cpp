#include "mainwindow.h"
#include <QApplication>
#include <qpushbutton.h>
#include <QWidget> 
#include <QSpinBox> 
#include <QSlider> 
#include <QHBoxLayout>

int main( int argc, char * argv[] )
{
	QApplication app( argc, argv );

	    QWidget *window = new QWidget;							//顶级窗口Qwidget类型
        window -> setWindowTitle( "Window" );					//窗口标题
 
        QSpinBox * spinBox	= new QSpinBox;						//有上下箭头的微调器
        QSlider	 * slider	= new QSlider( Qt::Horizontal );		//滑动杆
        spinBox -> setRange( 0, 130 );								//设置取值范围
        slider -> setRange( 0, 130 );									//设置取值范围
 
        QObject::connect( slider, SIGNAL( valueChanged( int ) ), spinBox, SLOT( setValue( int ) ) ); 
        QObject::connect( spinBox, SIGNAL( valueChanged( int ) ), slider, SLOT( setValue( int ) ) ); 
        spinBox -> setValue( 35 ); 
 
        QHBoxLayout * layout = new QHBoxLayout;				//水平布局 从左到右添加组件
        layout -> addWidget( spinBox );								// 添加微调器
        layout -> addWidget( slider );								// 添加滑动杆
        window -> setLayout( layout );								// 装载这个layout
 
        window->show();													//显示这个顶级窗口

	return app.exec();
}
