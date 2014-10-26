// 类中的静态:
// 对于一个类 有两种静态形式
class T
{
	private:
		static int m_num1;
		int m_num2;
	public:
		static int func1(){ return 1; };
		int func2(){ return 2; };
		static int func3(){ return m_num2; };
		int func4(){ return m_num1; };
		static int func5(){ return m_num1; };
};


// 静态成员变量 m_num1;
// 静态成员函数 func1();

// 静态成员是属于整个类的而不是某个对象;
// 静态成员变量只存储一份供所有对象共用;

// 例子:
T::func1();		//func1为静态函数 可以是用作用域解析符::  							TRUE
T::func2();		//func2为普通成员函数 属于某个对象 不能用作用域解析符:: 	FALSE


T t;
t.func1();		//可以通过对象来调用类的静态成员函数								TRUE
t.func2();		//普通的成员函数调用															TRUE

T t;
t.func3();		//在类的静态函数中使用类的非静态成员 								FALSE
					//类出错 静态函数在类未实例化之前就存在了 但是非静态成员变量依赖于实例;
					//所以这个静态函数引用了类的非静态成员出错
t.func4();		//在类的非静态函数中使用类的静态成员								TRUE


T t;
t.func5();		//编译出错,静态变量在使用之前应该初始化							FALSE
				//这个调用相当于使用了一个未初始化的变量
				//解决办法: 类后面加入 int T::m_num1 = 1;