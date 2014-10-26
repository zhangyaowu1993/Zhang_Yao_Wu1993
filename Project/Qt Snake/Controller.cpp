#include "Controller.h"
#include <qmessagebox.h>

Controller::Controller( QGraphicsScene *scene, QObject *parent )
	: QObject( parent )
{
	m_scene = scene;
	m_timer = new QTimer;
	m_GameResumeOrPause = false;
	m_snake = new Snake( this );
	m_food = new Food( 40, 60 );
	addNewFood();

	m_scene->addItem( m_snake );
	m_scene->addItem( m_food );
	
	m_timer->start( 1000 / 6 );
	m_scene->installEventFilter( this );
}


Controller::~Controller()
{

}

void Controller::addNewFood()
{
	int x, y;
	QTime time;
	do
	{
		time = QTime::currentTime();
		qsrand( time.msec() + time.second() * 1000 );
		x = ( int ) ( qrand() % 20 ) - 10;
		y = ( int ) ( qrand() % 20 ) - 10;

		x *= 20;
		y *= 20;
	}
	while( m_snake->shape().contains( m_snake->mapFromScene( QPointF( x + 5, y + 5 ) ) ) );
	m_food->setPos( x, y );
}

void Controller::snakeAteFood( Snake *snake, Food *food )
{
	m_snake->tail << *m_snake->m_head;
	m_snake->m_SnakeSize++;
	addNewFood();
}

void Controller::snakeAteItself( Snake *snake )
{
	m_GameResumeOrPause = true;
	this->m_scene->clear();

	m_food = new Food( 40, 40 );
	
	m_snake = new Snake( this );

	m_scene->addItem( m_snake );
	m_scene->addItem( m_food );

	addNewFood();
	m_snake->m_direction = Snake::Up;
	
	//resume_pause();
	emit GameOver();
}


bool Controller::eventFilter( QObject *object, QEvent *Event )
{
	if( Event->type() == QEvent::KeyPress )
	{
		handleKeyPress( ( QKeyEvent * ) Event );
		return true;
	}
	QObject::eventFilter( object, Event );
}

void Controller::handleKeyPress( QKeyEvent *Event )
{
	switch( Event->key() )
	{
		case Qt::Key_Up:
			if( m_snake->m_direction != Snake::Down )
			{
				m_snake->setDirection( Snake::Up );
			}
			break;
		case Qt::Key_Down:
			if( m_snake->m_direction != Snake::Up )
			{
				m_snake->setDirection( Snake::Down );
			}
			break;
		case Qt::Key_Left:
			if( m_snake->m_direction != Snake::Right )
			{
				m_snake->setDirection( Snake::Left );
			}
			break;
		case Qt::Key_Right:
			if( m_snake->m_direction != Snake::Left )
			{
				m_snake->setDirection( Snake::Right );
			}
			break;
	}
}

void Controller::resume_pause()
{
	if( m_GameResumeOrPause == false )
	{
		connect( m_timer, SIGNAL( timeout() ), m_scene, SLOT( advance() ) );
		m_GameResumeOrPause = true;
	}
	else
	{
		disconnect( m_timer, SIGNAL( timeout() ), m_scene, SLOT( advance() ) );
		m_GameResumeOrPause = false;
	}
}