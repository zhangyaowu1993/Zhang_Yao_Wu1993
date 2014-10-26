#include "mainwindow.h"
#include <QtWidgets/QApplication>
#include <qlabel.h>
#include <QPushButton>

int main( int argc, char * argv[] )
{
    QApplication app( argc, argv );				//一般由这句开始 这个对象用于管理Qt程序的生命周期 开启时间循环
 
    QPushButton button(	"Quit"	);				//创建了一个QPushButton 构造为Quit;
    QObject::connect( & button, & QPushButton::clicked, & QApplication::quit );
	//					sender;		signal;					slot;
	//当 button 发出了 clicked() 信号时  会调用 QApplication 的 quit() 函数 使程序退出

	//信号槽要求信号和槽的参数类型一致; 槽函数的参数可以比信号的少; 但必须一致

	//connect( sender, signal, receiver, slot );
	//connect函数常用形式; sender和receiver一般都是 QObject * 格式; 而signal和slot略有区别
	//这句话一般表示 sender发出了signal信号 receiver收到信号后 执行slot;
    button.show();

    return app.exec();								//开启事件循环 类似于一个无限循环;否则return了main退出就完了

}
