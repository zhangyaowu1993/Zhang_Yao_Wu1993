#pragma once

#include "qgraphicsitem.h"
#include <qpainter.h>

enum Data
{
	GameData_KEY
};
enum Type
{
	DataType_FOOD
};

class Food : public QGraphicsItem
{
	public:

	protected:
		QRectF boundingRect() const;
		QPainterPath shape() const;
		void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );
	public:
		Food( qreal x, qreal y );
		~Food();
};

