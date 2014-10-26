#include "paint.h"

Paint::Paint(QWidget *parent)
	: QWidget(parent)
{
	//ui.setupUi(this);
	QPixmap pixmap;
	pixmap.load( ":/Paint/Resources/123.png", 0, Qt::AvoidDither | Qt::ThresholdAlphaDither | Qt::ThresholdDither );		//资源地址 默认方式 避免抖动模式
	this->resize( pixmap.size() );																			//设置窗口大小为图片大小
	this->setMask( QBitmap( pixmap.mask() ) );														//为this设置一个遮罩 图片的透明部分实际上是一个遮罩

}

Paint::~Paint()
{

}

void Paint::mousePressEvent( QMouseEvent *Event )												//重写了鼠标按下事件
{
	if( Event->button() == Qt::LeftButton )															//左键按下 button()返回的是按下的事件
	{
		dragePosition = Event->globalPos() - frameGeometry().topLeft();						//保存下左键按下时的位置
		Event->accept();																					//接受处理这个事件 事件不在传播
	}
	if( Event->button() == Qt::RightButton )															//右键按下
	{
		close();																									//关闭
	}
}

void Paint::mouseMoveEvent( QMouseEvent *Event )												//重写了鼠标移动事件
{
	if( Event->buttons() & Qt::LeftButton )															//左键有被按下的状态 buttons()返回的是按键的状态的位组合 所以要判断左键 也有可能是左键加右键 那用==就没有效果了
	{
		move( Event->globalPos() - dragePosition );													//移动窗口 当前位置减去原始位置
		Event->accept();																					//接受处理这个事件 事件不在传播
	}
}

void Paint::paintEvent( QPaintEvent *Event )														//重写了Paint事件
{
	QPainter painter( this );																				//重画了自己
	painter.drawPixmap( 0, 0, QPixmap( ":/Paint/Resources/123.png" ) );						//用这张图重画
}

//在qrc文件中可以看到加载的资源的地址 如果编译release版本需要copy一份资源