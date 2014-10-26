QT中的MessageBox

if( QMessageBox::question( this, tr( "Question" ), tr( "Are you OK?" ), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes ) == QMessageBox::Yes )
{
	QMessageBox::information( this, tr( "Hmmm..." ), tr( "I'm glad to hear that!" ) );
}
else
{
	QMessageBox::information( this, tr( "Hmmm..." ), tr( "I'm sorry!" ) );
}

QMessageBox::question( 父窗口, 标题, 内容, 按钮 );

	QMessageBox::information( this, "TITLE", "TEXT" );
	QMessageBox::warning( this, "TITLE", "TEXT" );
	QMessageBox::information( this, "TITLE", "TEXT", QMessageBox::YesToAll | QMessageBox::NoToAll );

	QMessageBox::StandardButton reply;
	reply = QMessageBox::question( this, "TITLE", "TEXT", QMessageBox::Yes | QMessageBox::No );
	if( reply == QMessageBox::Yes )
	{
		QMessageBox::information( this, "TITLE", "Yes" );
	}
	else
	{
		QMessageBox::information( this, "TITLE", "No" );
	}