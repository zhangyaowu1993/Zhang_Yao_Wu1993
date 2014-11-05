#include "Snake.h"

Snake::Snake( Controller *controller )
{
	m_head = new QPointF( 0, 0 );
	tail << QPointF( 0, 60 ) << QPointF( 0, 40 ) << QPointF( 0, 20 );
	m_controller = controller;
	m_direction = Up;
	m_SnakeSize = 4;
}


Snake::~Snake()
{

}

QRectF Snake::boundingRect() const
{
	qreal minX = m_head->x();
	qreal minY = m_head->y();
	qreal maxX = m_head->x();
	qreal maxY = m_head->y();

	foreach( QPointF p, tail )
	{
		maxX = p.x() > maxX ? p.x() : maxX;
		maxY = p.y() > maxY ? p.y() : maxY;
		minX = p.x() < minX ? p.x() : minX;
		minY = p.y() < minY ? p.y() : minY;
	}
	QPointF tl = mapFromScene( QPointF( minX, minY ) );
	QPointF br = mapFromScene( QPointF( maxX, maxY ) );

	QRectF bound = QRectF( tl.x(), tl.y(), br.x() - tl.x() + 20, br.y() - tl.y() + 20 );
	return bound;
}

QPainterPath Snake::shape() const
{
	QPainterPath path;
	path.setFillRule( Qt::WindingFill );
	path.addRect( 3, 3, 14, 14 );
	foreach( QPointF p, tail )
	{
		QPointF itemp = mapFromScene( p );
		path.addRect( QRectF( itemp.x() + 3, itemp.y() + 3, 14, 14 ) );
	}
	return path;
}

void Snake::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
{
	QTime time;
	int index = 0;
	QPixmap	pixmap[5] = { ":/MainWindow/Resources/blue.png", ":/MainWindow/Resources/purple.png" };
	painter->drawPixmap( 3, 3, 14, 14, pixmap[0] );
	foreach( QPointF p, tail )
	{
		QPointF itemp = mapFromScene( p );
		painter->drawPixmap( itemp.x() + 3, itemp.y() + 3, 14, 14, pixmap[1] );
	}
}

void Snake::setDirection( Direction direction )
{
	m_direction = direction;
}

void Snake::MoveUp()
{
	m_head->ry() <= -200 ? m_head->ry() = 180 : m_head->ry() -= 20;
}

void Snake::MoveDown()
{
	m_head->ry() >= 180 ? m_head->ry() = -200 : m_head->ry() += 20;
}

void Snake::MoveLeft()
{
	m_head->rx() <= -200 ? m_head->rx() = 180 : m_head->rx() -= 20;
}

void Snake::MoveRight()
{
	m_head->rx() >= 180 ? m_head->rx() = -200 : m_head->rx() += 20;
}

void Snake::advance( int step )
{
	if( step == 0 )
	{
		return;
	}
	tail.takeFirst();
	tail << *m_head;
	switch( m_direction )
	{
		case Up:
			MoveUp();
			break;
		case Down:
			MoveDown();
			break;
		case Left:
			MoveLeft();
			break;
		case Right:
			MoveRight();
			break;
	}
	setPos( *m_head );
	handleCollisions();
}

void Snake::handleCollisions()
{
	QList< QGraphicsItem *> collisions = collidingItems( Qt::IntersectsItemShape );

	foreach( QGraphicsItem *collidingItem, collisions )
	{
		if( collidingItem->data( GameData_KEY ) == DataType_FOOD )
		{
			m_controller->snakeAteFood( this, ( Food * ) collidingItem );
			return;
		}
	}
	if( tail.contains( *m_head ) )
	{
		m_controller->snakeAteItself( this );
		return;
	}
}