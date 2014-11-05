QT2::QT2( QWidget *parent ) : QMainWindow( parent )
{
	//ui.setupUi( this );

	QPushButton *pushButton1 = new QPushButton( this );
	QPushButton *pushButton2 = new QPushButton( this );

	pushButton1->setText( "pushButton1" );
	pushButton2->setText( "pushButton2" );


	QWidget *widget = new QWidget();
	this->setCentralWidget( widget );

	QVBoxLayout *mainLayout = new QVBoxLayout( this ); 
	mainLayout->addWidget( pushButton1 );
	mainLayout->addWidget( pushButton2 );
	centralWidget()->setLayout( mainLayout );

	this->setWindowTitle( "fake" );

}



QT学习之路-布局:
QT里有三大类窗口: QMainWindow, QWidget, QDialog;

QWidget类是所有用户界面对象的基类:部件
窗口部件是用户界面的一个基本单元:
它从窗口系统接收鼠标 键盘和其它事件 并且在屏幕上绘制自己
每一个窗口部件都是矩形的 并且它们按Z轴顺序排列
一个窗口部件可以被它的父窗口部件或者它前面的窗口部件盖住一部分


QMainWindow类提供一个有菜单条、锚接窗口（例如工具条）和一个状态条的主应用程序窗口
主窗口通常用在提供一个大的中央窗口部件（例如文本编辑或者绘制画布）以及周围 菜单、工具条和一个状态条
QMainWindow常常被继承，因为这使得封装中央部件、菜单和工具条以及窗口状态条变得更容易
当用户点击菜单项或者工具条按钮时，槽会被调用。

QDialog类是对话框窗口的基类
对话框窗口是主要用于短期任务以及和用户进行简要通讯的顶级窗口
QDialog可以是模态对话框也可以是非模态对话框
QDialog支持扩展性并且可以提供返回值 它们可以有默认按钮
QDialog 是最普通的顶级窗口
一个不会被嵌入到父窗口部件的窗口部件叫做顶级窗口部件
通常情况下，顶级窗口部件是有框架和标题栏的窗口（尽管使用了一定的窗口部件标记，创建顶级窗口部件时也可能没有这些装饰。）
在Qt中，QMainWindow和不同的QDialog的子类是最普通的顶级窗口


如果是主窗体，那就基于QMainWindow
如果是顶级对话框，那就基于QDialog创建
如果不确定，或者有可能作为顶级窗体，或有可能"嵌入到其他窗体中"，则基于QWidget创建

/****************************************************************************************/

在QT创建工程时 会选择加入默认的窗口;可以选择继承的基类;这里就可以选择QMainWindow, QDialog, QWidget;
在创建好工程后 主要有一个头文件假设为QT.h 一个对应的源文件为QT.cpp 还有一个main.cpp
还有一个QT.ui 这个就是ui创建的框架,可以通过ui来进行构建;
还有一个是ui对应的头文件 ui_QT.h 由于VS2013的一些问题 导致我们每次新建完ui后 要copy ui的code到这个头文件

在QT.h里放的是一个基于前面选择的窗口类创建的子类;
这个子类里有
Q_OBJECT 	这是一个QT的宏,他的作用就是有了他 才能在QT中使用signal & slots 机制
public:		这里默认有一个构造函数和析构函数
private:	这里默认是一个Ui::QT1Class ui; 这个就是创建了一个与ui对应的变量;
signals:	这个是QT的信号 一般是一个函数 可以不实现
private slots: 这个是QT的私有槽 是一个函数 必须实现 一般与signals参数对应

在说QT.cpp:
这个里面就是QT.h的实现
有一个QT1::QT1( QWidget *parent ) : QWidget( parent ) 这个是构造函数
里面是 ui.setupUi( this ); 指的是把this设置为ui , this就是这个新建的对象;
然后就是析构;没了;

还有个main.cpp:

int main( int argc, char *argv[] )	//这个是普通的main函数入口
{
	QApplication a(argc, argv);		//把main函数的两个参数给了QApplication; 必须
	QT1 window;							// 创建了一个QT1对象window
	window.show();						//把window show出来;
	return a.exec();						//进入消息循环; 必须
}

这就是QT大概的样子; 现在我们尝试加入一些东西:

在QWidget类下的窗口创建: 首先我们不使用ui;所以把头文件和源文件里的和ui有关的注释掉
然后在这个类的构造函数中 我们加入了3个button
QPushButton *pushButton1 = new QPushButton( this );		//这个this代表的是实例化时候的这个对象
QPushButton *pushButton2 = new QPushButton( this );		//那么这句的意思就是 创建了一个button
QPushButton *pushButton3 = new QPushButton( this );		//他的父窗口是this, this就是这个新建的window

pushButton1->setText( "Button1" );								//给三个button起个名字;
pushButton2->setText( "Button2" );
pushButton3->setText( "Button3" );

QVBoxLayout *Layout = new QVBoxLayout( this );				//布局
Layout->addWidget( pushButton1 );
Layout->addWidget( pushButton2 );
Layout->addWidget( pushButton3 );

首先解释一下
QVBoxLayout *Layout = new QVBoxLayout( this ); 			
//这句是把 this 即 window 的布局设置为Layout;
//然后后面三句就是往这个布局里加东西 V代表竖向布局;

然后最后一段还有一种写法:
QVBoxLayout *Layout = new QVBoxLayout;
......
this->setLayout( Layout );
//这种就是先设置了一个布局 在布局里加入了东西 在把布局给了window

//其实这里不加this也可以,qt会自动生成父子关系..

好了 这段布局的代码在QWidget生成的窗口里是有效的 但是到QMainWindow里就无效了
因为QMainWindow本身已经有了一个布局 我们无法再次加入一个新的布局 解决办法:

QWidget *widget = new QWidget;		//首先创建了一个QWidget实例

QHBoxLayout *mainLayout = new QHBoxLayout;	//这段和上面一样 创建了一个布局
......

widget->setLayout( mainLayout );		//把这个layout给了widget;
this->setCentralWidget( widget );		//然后把这个实例设置为centralWidget;

问题解决, 这样我们就可以在QMainWindow或者QWidget上创建按钮了 
同样方法也可以创建 lineEdit,progressBar等等;