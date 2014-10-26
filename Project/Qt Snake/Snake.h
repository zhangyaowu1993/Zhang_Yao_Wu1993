#pragma once
//#include "Controller.h"

#include <qgraphicsitem.h>
#include <qpainter.h>
#include <qlist.h>
#include "Controller.h"

class Controller;

class Snake : public QGraphicsItem
{
	public:
	enum Direction
	{
		Left, Right, Up, Down
	};


	private:
		
		Controller *m_controller;
		
		

		void MoveUp();
		void MoveDown();
		void MoveLeft();
		void MoveRight();

	protected:
		QRectF boundingRect() const;
		
		void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );
		void advance( int step );
		void handleCollisions();

	public:
		Snake( Controller *controller );
		~Snake();
		void setDirection( Direction direction );
		QPainterPath shape() const;
		QPointF *m_head;
		QList< QPointF > tail;
		int m_SnakeSize; 
		Direction m_direction;
};

