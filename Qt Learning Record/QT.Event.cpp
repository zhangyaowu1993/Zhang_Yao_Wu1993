#include "label.h"

CustomButton::CustomButton( QWidget *parent ) : QPushButton( parent )
{
	connect( this, SIGNAL( clicked() ), this, SLOT( onButtonClicked() ) );
}

void CustomButton::onButtonClicked()
{
	QMessageBox::information( this, QStringLiteral( "标题" ), QStringLiteral( "按了左键" ) );
}

void CustomButton::mousePressEvent( QMouseEvent *event )					//这个是CustonButton类的按左键函数
{
	if( event->button() == Qt::LeftButton )
	{
		QMessageBox::information( this, QStringLiteral( "标题" ), QStringLiteral( "左键" ) );
	}
	else
	{
		QPushButton::mousePressEvent( event );									//这个是父类QPushButton类的按左键函数
	}
}

//首先 我们定义了一个按钮 clicked()的时候执行槽函数 onButtonClicked() 弹出一个"按了左键"消息框
//然后 我们重写了父类的一个函数 mousePressEvent() 然后判断如果这个事件是左键按下 则弹出"左键"消息框 现在这个函数是子类的函数
//如果不是左键事件 我们则调用了父类的mousePressEvent(); 然后我们在执行的时候发现 左键点击"*只执行了我们的子类函数*";
//解释: 第一 父类的mousePressEvent()函数中 emit出了一个clicked()信号 那么我们重写这个函数之后 emit没有了 所以我们的槽函数也就不在执行
//所以如果我们需要写一个函数时 确保我们的确需要覆盖父类的某一个函数;

//然后在看我们自己重写了个mousePressEvent函数. 如果消息是左键 则执行"左键"消息框,否则把这个事件交给了父类来处理
//而这个程序里 点击右键本身也没啥作用 所以如果要测试 可以把LeftButton改为RightButton;
//然后如果调用了父类的同名函数 则可以把这样视为一个链子 如果自己不处理 则交给父类处理
//而一个事件对象 Event 他会有两个函数 accept() 和 ignore(); 
//前者用来表示这个类的事件函数愿意处理这个事件, 所以这个事件就不会在往上传播
//后者用来表示这个类的事件函数不愿意处理这个事件,这个事件继续传播 ;  处理中可以使用 isAccept() 来查询是否已被接受

/*
void QWidget::mousePressEvent( QMouseEvent *event )				//这是一个基于QWidget的事件函数
{
	event->ignore();																	//如果这个函数的子类都没有处理这个事件 那么这个事件默认是忽略的
	if( ( windowType() == Qt::Popup ) )										//如果我们的子类accpet()了 则下面的代码就不会执行 
	{
		event->accept();
		QWidget* w;
		while( ( w = QApplication::activePopupWidget() ) && w != this )
		{
			w->close();
			if( QApplication::activePopupWidget() == w )
				w->hide(); // hide at least
		}
		if( !rect().contains( event->pos() ) )
		{
			close();
		}
	}
}
*/

//关于事件处理;加入我们想处理一个TAB事件
/*
bool CustomWidget::event( QEvent *Event )								//CustomWidget是Widget的一个子类 我们重写了他的event函数
{
	if( Event->type() == QEvent::KeyPress )									//如果这个事件的类型是KeyPress
	{
		QKeyEvent *keyEvent = static_cast<QKeyEvent *>( Event );	//设置一个QKeyEvent对象 keyEvent , 把Event给了他的键值
		if( keyEvent->key() == Qt::Key_Tab )									//如果这个对象keyEvent的键值==Tab
		{
			qDebug() << "You press tab.";										//qDebug()
			return true;																//返回true表示我们已经处理这个事件
		}
	}
	return QWidget::event( Event );												//如果这个事件类型不是KeyPress或者不是Tab 他会交给父类的event函数处理
}
*/