#include "mainwindow.h"

MainWindow::MainWindow( QWidget *parent )
	: QMainWindow( parent ),
	m_scene( new QGraphicsScene( this ) ),
	m_view( new QGraphicsView( m_scene, this ) ),
	m_controller( new Controller( m_scene, this ) )
{
	ui.setupUi(this);
	ui.widget->setContentsMargins( -11, -11, -11, -11 );
	ui.pushButton->setText( QStringLiteral( "开 始" ) );
	ui.pushButton_2->setText( QStringLiteral( "退 出" ) );
	
	m_ResumeOrPause = true;
	m_GameTime = 0;
	m_timer = new QTimer();
	m_timer->start( 1000 );

	connect( ui.pushButton, SIGNAL( clicked() ), m_controller, SLOT( resume_pause() ) );
	connect( ui.pushButton, SIGNAL( clicked() ), this, SLOT( ChangeTextResumeOrPause() ) );
	connect( ui.pushButton_2, SIGNAL( clicked() ), this, SLOT( close() ) );
	connect( m_controller, SIGNAL( GameOver() ), m_controller, SLOT( resume_pause() ) );
	connect( m_controller, SIGNAL( GameOver() ), this, SLOT( WindowGameOver() ) );

	QPixmap pixmap = QPixmap( ":/MainWindow/Resources/Pe.jpg" ).scaled( this->size() );
	QPalette palette( this->palette() );
	palette.setBrush( QPalette::Background, QBrush( pixmap ) );
	this->setPalette( palette );

	QHBoxLayout *Layout = new QHBoxLayout;
	Layout->addWidget( m_view );
	ui.widget->setLayout( Layout );

	DrawBackGround();
}

MainWindow::~MainWindow()
{

}

void MainWindow::DrawBackGround()
{
	//QPixmap *pixmap = new QPixmap( 200, 200 );
	//QPainter *painter = new QPainter( pixmap );
	//painter->drawRect( 0, 0, 200, 200 );
	//m_scene->setBackgroundBrush( ( QBrush ) *pixmap  );
	m_view->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
	m_view->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
	m_view->setStyleSheet( "background: transparent;" );
	m_view->setWindowFlags( Qt::FramelessWindowHint );
	m_scene->setSceneRect( -200, -200, 400, 400 );
}

void MainWindow::ChangeTextResumeOrPause()
{
	if( m_ResumeOrPause == false )
	{
		ui.pushButton->setText( QStringLiteral( "继 续" ) );
		m_ResumeOrPause = true;
		disconnect( m_timer, SIGNAL( timeout() ), this, SLOT( ChangeLcdText() ) );
	}
	else
	{
		ui.pushButton->setText( QStringLiteral( "暂 停" ) );
		m_ResumeOrPause = false;
		connect( m_timer, SIGNAL( timeout() ), this, SLOT( ChangeLcdText() ) );
	}
}

void MainWindow::ChangeLcdText()
{
	m_GameTime++;
	ui.lcdNumber->display( m_GameTime );
}

void MainWindow::WindowGameOver()
{
	m_GameTime = 0;
	m_ResumeOrPause = true;
	disconnect( m_timer, SIGNAL( timeout() ), this, SLOT( ChangeLcdText() ) );
	ui.pushButton->setText( QStringLiteral( "重 来" ) );
}