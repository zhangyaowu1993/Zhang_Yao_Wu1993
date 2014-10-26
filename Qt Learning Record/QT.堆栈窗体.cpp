Dialog::Dialog( QWidget *parent ) : QDialog( parent )
{
	//ui.setupUi( this );
	QLabel *Label1 = new QLabel( tr( "Label1" ) );
	QLabel *Label2 = new QLabel( tr( "Label2" ) );
	QLabel *Label3 = new QLabel( tr( "Label3" ) );

	QListWidget *list = new QListWidget( this );
	list->insertItem( 0, tr( "Window1" ) );
	list->insertItem( 1, tr( "Window2" ) );
	list->insertItem( 2, tr( "Window3" ) );

	QStackedWidget *stack = new QStackedWidget( this );
	stack->addWidget( Label1 );
	stack->addWidget( Label2 );
	stack->addWidget( Label3 );

	QHBoxLayout *Layout = new QHBoxLayout( this );
	Layout->setMargin( 5 );
	Layout->setSpacing( 5 );
	Layout->addWidget( list );
	Layout->addWidget( stack, 0, Qt::AlignHCenter );
	Layout->setStretchFactor( list, 1 );
	Layout->setStretchFactor( stack, 3 );
	connect( list, SIGNAL( currentRowChanged( int ) ), stack, SLOT( setCurrentIndex( int ) ) );
}