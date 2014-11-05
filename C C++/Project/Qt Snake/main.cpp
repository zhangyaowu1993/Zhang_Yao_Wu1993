#include "mainwindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QString qss;
	QFile qssFile( ":/MainWindow/Resources/ui.qss" );
	qssFile.open( QFile::ReadOnly );
	if( qssFile.isOpen() )
	{
		qss = QLatin1String( qssFile.readAll() );
		qApp->setStyleSheet( qss );
		qssFile.close();
	}

	MainWindow w;
	w.show();

	return a.exec();
}
