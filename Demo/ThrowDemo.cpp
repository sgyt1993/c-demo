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
	//�����1
}*/

//�����Լ���excepyion
/*class myexception :public exception 
{
	virtual const char* what() const throw() 
	{
		return "My exception happened";
	}
}myex;

//���ܸĺ���Υ�����쳣˵�������Ǳ���������˳�������
void f() noexcept //��ŵ�����׳��쳣
{
	throw myex;//Υ�����쳣˵�����������terminate,��ֹ����
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

//�����ռ�
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
	//ֱ�Ӱ�����FifthEd������
	clc::A a();
	//clc::B b();���������������ܷ���
	return 0;
}*/



//��̳�
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
	//����D1��ͼ�����������ж�����D1::D1(const string &)
	using Base1::Base1;//Base1�̳й��캯��
	using Base2::Base2;//Base2�̳й��캯��
	//D1������һ���������string�Ĺ��캯��
	D1() = default;
	D1(const string &s) :Base1(s), Base2(s) {};
};*/








