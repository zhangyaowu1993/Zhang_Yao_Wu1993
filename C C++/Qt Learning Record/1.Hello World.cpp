#include "mainwindow.h"
#include <QtWidgets/QApplication>
#include <qlabel.h>

int main( int argc, char * argv[] )
{
    QApplication app( argc, argv );		//一般由这句开始 这个对象用于管理Qt程序的生命周期 开启时间循环
 
    QLabel label( "Hello, world" );			//创建一个Qlabel对象 构造函数赋值( "" ); 在栈上创建
    label.show();								//调用label的方法 show();
 
    return app.exec();						//开启事件循环 类似于一个无限循环;否则return了main退出就完了
}
