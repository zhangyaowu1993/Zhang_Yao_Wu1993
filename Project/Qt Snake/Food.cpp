#include "Food.h"


Food::Food( qreal x, qreal y )
{
	this->setData( GameData_KEY, DataType_FOOD );
	this->setPos( x, y );
}


Food::~Food()
{

}

QRectF Food::boundingRect() const
{
	QRectF rect( 0, 0, 20, 20 );
	return rect;
}

QPainterPath Food::shape() const
{
	QPainterPath path;
	path.addRect( 3, 3, 14, 14 );
	return path;
}

void Food::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
{
	painter->drawPixmap( 3, 3, 14, 14, QPixmap( ":/MainWindow/Resources/heart.png" ) );
}