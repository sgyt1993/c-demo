#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//重构运算符函数
/*class  OperatorA{
private:
	int num;
public:
	OperatorA() = default;
	OperatorA(int k) {
		num = k;
	};
	OperatorA& operator +=(OperatorA &b) {
		num += b.num;
		return *this;
	};
	int get() {
		return num;
	}
};



int main() 
{
	OperatorA a(5);
	OperatorA b(3);
	 a += b;
	cout << a.get() << endl;
	cout << b.get() << endl;
	return 0;
}*/


//重载输出运算符<<
/*class OperatorStream {
private:
	int id;
	string name;
	int age;
public:
	OperatorStream() = default;
	OperatorStream(int id, string name, int age) {
		this->age = age;
		this->name = name;
		this->id = id;
	};
	friend ostream& operator << (ostream &os, const OperatorStream &item) 
	{
		os << item.id << "     " << item.name << "       " << item.age;
		return os;
	}
	friend istream& operator>>(istream &ws,  OperatorStream &item) 
	{
		ws >> item.id >> item.name >> item.age;
		return ws;
	};
};

int main() 
{
	//键盘输入的，读入的
	OperatorStream a(1, "sgyt", 26);
	cout << a << endl;//1    sgyt   26
	OperatorStream b;
	cin >> b;//2   sg  28
	cout << b;//2   sg  28

	//文件读入，输出
	ofstream  ws("e:/sgyt.txt",ios::out);
	if (ws.fail()) {
		cout << "打开文件失败" << endl;
		exit(0);
	}
	ws << a << endl;
	OperatorStream ord;
	ifstream rd("e:/sgyt.txt");
	rd >> ord;
	cout <<"ord:"<< ord;//1    sgyt   26
	return 0;
}*/


//下标运算符
/*#include"arrayDemo.h"

int main() 
{
	ArrayDemo a(3);
	a[0] = 3;
	a[1] = 2;
	a[2] = 1;
	a.display();
	return 0;
}*/


//成员访问运算符
/*#include"ObjectOverLoad.h"
int main()
{
	operatorDemo a("sss");
	cout << a->size() << endl;
	return 0;
}*/

//函数调用运算符
/*class abInt 
{
private:
	int s;
public:
	abInt() :s(2) {};
	abInt(int k) //初始化
	{
		this->s = k;
	};
	int operator()(int val)//调用的运算符
	{
		return s = s + val;
	};
	int get() const {
		return s;
	}
};

int main() 
{
	abInt a(3);
	cout << a.get() << endl;
	a(6);
	cout << a.get() << endl;
	return 0;
}*/

//标准库中的函数对象
/*#include<functional>
#include <algorithm>
int main()
{
	pair<int*, int*> ptiter;
	int foo[] = { 10,20,30,40,50 };
	int bar[] = { 10,20,40,80,50 };
	ptiter = mismatch(foo, foo + 5,bar, equal_to<int>());
	cout << *ptiter.first << endl;//30
	cout << *ptiter.second << endl;//40
	return 0;
}*/

/*class  DemoStr 
{
public:
	DemoStr() = default;
	DemoStr(string l) {
		this->m = l;
	}
	DemoStr(int l) {
		this->k = l;
	}
	operator int() 
	{
		cout << "类型转换" << endl;
		return k;
	}
private:
	int k;
	string m;
};

//重载类型转换
int  main()
{
	DemoStr s(1221);
	//int m = int(s);
	//DemoStr sl = 5;//这中是显示转换
	//int o = s;//将类型转换，这种是隐式转换
	int add = s + 3;//先将s转换为int,在进行加减法
	//cout << m << endl;
	cout << add << endl;
	//cout << sl << endl;
	return 0;
}*/


//避免有二义性的类型转换
//函数匹配与重载运算符
/*class SmallInt 
{
	friend SmallInt operator+(const SmallInt&, const SmallInt&);
public:
	SmallInt(int = 0);
	operator int() const { return val; };
private:
	size_t val;
};*/

/*
		第一条加法语句是使用operator+的方法，是唯一的
		第二条语句有两种翻译：
				1.将4转换成SmallInt,然后使用SmallInt的operator+
				2.将s3转换成int,然后用两个int执行内置的加法运算
	*/
	/*int  main()
{
	SmallInt s1, s2;
	SmallInt s3 = s1 + s2;//使用的是operator+
	//int i = s3 + 4;//二义性问题，
}*/
