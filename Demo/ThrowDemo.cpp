#include<iostream>
#include<string>
#include<exception>
using namespace std;
/*int main() 
{
	try 
	{
		throw 1;
		throw "error";
	}
	catch (char *str) 
	{
		cout << str << endl;
	}
	catch (int s) 
	{
		cout << s << endl;
	}
	//输出是1
}*/

//定义自己的excepyion
/*class myexception :public exception 
{
	virtual const char* what() const throw() 
	{
		return "My exception happened";
	}
}myex;

//尽管改函数违反了异常说明，但是编译器可以顺利编译的
void f() noexcept //承诺不会抛出异常
{
	throw myex;//违反了异常说明，程序调用terminate,终止程序
}
int main()
{
	f();
	return 0;
}*/
/*int main() 
{
	try {
		throw myex;
	}
	catch(exception& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}*/

/*
void f1() 
{
	try 
	{
		throw 1;
	}
	catch (int s) {
		cout << s << endl;
	}
}
int main()
{
	if(noexcept(f1()))
	{
		cout << "no except" << endl;
	}
	else {
		cout << "have except" << endl;
	};
	return 0;
	
}*/
/*
		have except
*/

//命名空间
/*
namespace sgyt_plus 
{
	class A {
		public:
			A() = default;


	};
}
int main()
{
	sgyt_plus::A a();
	return 0;
}*/




/*namespace clc {
#include"FifthEd.h"
}
int main() 
{
	//直接包含了FifthEd的内容
	clc::A a();
	//clc::B b();非内联函数，不能访问
	return 0;
}*/



//多继承
/*struct Base1 
{
	Base1() = default;
	Base1(const string &s) {};
	Base1(shared_ptr<int> d) {};
};
struct  Base2
{
	Base2() = default;
	Base2(const string &s) {};
	Base2(int &k) {};
};

struct D1 :public Base1, public Base2 
{
	//错误：D1试图从两个基类中都集成D1::D1(const string &)
	using Base1::Base1;//Base1继承构造函数
	using Base2::Base2;//Base2继承构造函数
	//D1必须有一个定义接受string的构造函数
	D1() = default;
	D1(const string &s) :Base1(s), Base2(s) {};
};*/








