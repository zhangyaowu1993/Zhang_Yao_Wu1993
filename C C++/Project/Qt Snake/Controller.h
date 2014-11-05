#pragma once

#include <qobject.h>
#include <qgraphicsscene.h>
#include <qevent.h>
#include <qtimer.h>
#include <qdatetime.h>

#include "Snake.h"
#include "Food.h"

class Snake;
class Food;

class Controller : public QObject
{
	Q_OBJECT

	private:
		QGraphicsScene *m_scene;

		QTimer *m_timer;
		bool m_GameResumeOrPause;

		void addNewFood();
		

		void handleKeyPress( QKeyEvent *Event );
	protected:
		bool eventFilter( QObject *object, QEvent *Event );
		
	public:
		Controller( QGraphicsScene *scene, QObject *parent = 0 );
		~Controller();
		void snakeAteFood( Snake *snake, Food *food );
		void snakeAteItself( Snake *snake );
		Snake *m_snake;
		Food *m_food;
		

	public slots:
		void resume_pause();
	signals:
		void explains();
		void GameOver();
};

