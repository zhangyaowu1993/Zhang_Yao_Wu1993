	QString qss;
	QFile qssFile( ":/DrawText/Resources/skin.qss" );
	qssFile.open( QFile::ReadOnly );
	if( qssFile.isOpen() )
	{
		qss = QLatin1String( qssFile.readAll() );
		qApp->setStyleSheet( qss );
		QMessageBox::information( NULL, "asd", "asd" );
		qssFile.close();
	}