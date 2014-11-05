
#include <QtCore/QCoreApplication>
#include <qdebug.h>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QList< QString > list0;													//创建了一个存放QString类型的list0;
	QString str1( "str1" );													//创建两个QString类型对象str1 str2
	QString str2( "str2" );
	list0 << str1 << str2;													//放入list0中;
	qDebug() << list0[0] << list0[1];										//输出

	//qDebug中带有双引号代表这个输出的是一个QString类型 不是把引号放入了串
	//如果输出list0 则会有(); 表示是串的集合

	QList< int > list;															//创建一个int的list
	QMutableListIterator< int > list_Iterator( list );					//可修改的迭代器
	for( int i = 0; i < 10; i++ )
	{
		list_Iterator.insert( i );												//插入数据
	}

	for( list_Iterator.toFront(); list_Iterator.hasNext(); )			//把迭代器放在表头前面一点,然后如果迭代器后面有数据 则进入
	{
		qDebug() << list_Iterator.next();								//迭代器调用next 迭代器越过后面的数据, 输出他越过的数据
	}

	for( list_Iterator.toBack(); list_Iterator.hasPrevious(); )		//迭代器放在表尾; 如果前面有数据 则进入
	{
		if( list_Iterator.previous() % 2 == 0 )							//如果迭代器越过的数据是偶数 则
		{
			list_Iterator.remove();											//删除这个数据
		}
		else
		{
			list_Iterator.setValue( list_Iterator.peekNext() * 10 );//否则把这个数据乘以10; peekNext() 返回下一个列表项但不移动迭代器
		}
	}

	for( list_Iterator.toFront(); list_Iterator.hasNext(); )			//迭代器放在表头
	{
		qDebug() << list_Iterator.next();								//输出数据
	}


	return a.exec();
}
