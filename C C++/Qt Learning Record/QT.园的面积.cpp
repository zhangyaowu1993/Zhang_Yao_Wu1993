计算园的面积:
首先 在ui层里创建一个lineEdit 一个pushButton
然后在对象的构造函数里加入信号槽
connect( ui.pushButton, SIGNAL( clicked() ), this, SLOT( Area() ) );

然后在类中加入槽函数声明:
private slots:
	void Area();

写出槽函数的定义:
void Dialog::Area()
{
	QString str = ui.lineEdit->text();
	QString strtemp;
	bool ok;
	int valueint = str.toInt( &ok );
	double area = 3.14 * valueint * valueint;
	ui.lineEdit->setText( strtemp.setNum( area ) );
}

这个例子可以注意的是:
第一 我们可以用QString类型来获得lineEdit里的内容
第二 我们如果要使用toInt 必须构造一个bool ok 然后使用str.tiInt( &ok );
第三 我们可以setText但是需要一个strtemp 使用strtemp.setNum();