QGraphicsView FrameWork

QGraphicsScene 场景
QGraphicsView  视图
QGraphicsItem  部件

对于item类,必须重写:
QRectF boundingRect() const;
void paint( QPainter *painter, const QStyleOptionGraphicsItem*option, QWidget *widget );

可选重写
QPainterPath shape() const;
void advance( int step );
void handleCollisions();