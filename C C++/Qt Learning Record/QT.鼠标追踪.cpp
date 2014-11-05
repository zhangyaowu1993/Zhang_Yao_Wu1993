/*****************************/// label.h
class EventLabel : public QLabel
{
	Q_OBJECT
private:
	void mouseMoveEvent( QMouseEvent *event );
	void mousePressEvent( QMouseEvent *event );
	void mouseReleaseEvent( QMouseEvent *event );

};

/*****************************/// label.cpp
void EventLabel::mouseMoveEvent( QMouseEvent *event )
{
	this->setText( QString( "<center><h1>Move: (%1, %2)</h1></center>" ).arg( QString::number( event->x() ), QString::number( event->y() ) ) );
}

void EventLabel::mousePressEvent( QMouseEvent *event )
{
	this->setText( QString( "<center><h1>Press: (%1, %2)</h1></center>" ).arg( QString::number( event->x() ), QString::number( event->y() ) ) );
}

void EventLabel::mouseReleaseEvent( QMouseEvent *event )
{
	this->setText( QString( "<center><h1>Release: (%1,%2</h1></center>" ).arg( QString::number( event->x() ), QString::number( event->y() ) ) );
}

/*****************************/// main.cpp
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	EventLabel w;
	w.resize( 300, 200 );
	w.setMouseTracking( true );
	w.show();
	return a.exec();
}

//解释如下:首先 在所有组件的父类QWidget中 定义了许多事件的回调函数
//那么我们这里的QLabel父类自然也有这些回调函数 而且这些函数是虚函数
//我们这里从QLabel派生出一个EventLabel类 那么他就拥有了QLabel的特性
//我们在EventLabel里重写了QLabel类的三个事件函数
//那么我们的EventLabel就重定义了这三个函数 分别是点击 移动 释放
//第二 因为自定义了一个Widget之后 如果没有指定父窗口 他会自己成为一个窗口
//所以我们要resize一下放大一点;
//第三 关于w.setMouseTracking( true ); 在QWidget中有一个mouseTracking属性
//他默认为false 就是要点击一次鼠标之后才为true;才能发出MouseMoveEvent()事件
//所以我们直接设置为true;让他直接可以发出这个事件