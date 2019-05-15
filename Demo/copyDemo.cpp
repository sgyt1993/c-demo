#include<iostream>
#include<string>
#include"DemoClass.h"
#include"MyStr.h"
using namespace std;

void  getA(A c) {
	cout << "getA called\n" << endl;
}

/*int main()
{
	string  null_book = "0009999";
	string kk("9999999");
	A a(100);
	A b = a;
	b.show();
	getA(b);
	return 0;
}*/

//这个是拷贝，赋值，析构的案例
/*int main() 
{

	MyStr str1(1, "swdw");
	cout << "======================" << endl;
	MyStr str2;//使用默认构造
	str2 = str1;//因为str2使用默认构造生成了Mystr的实例，所以用赋值构造函数
	cout << "=======================" << endl;
	MyStr str3 = str2;//使用拷贝函数
	return 0;
}*/

//浅拷贝，深拷贝


//swqp交换
void swap(MyStr &a, MyStr& b) {
	using std::swap;
	swap(a.id, b.id);
	swap(a.name, b.name);//有效的方式再次创建一个对象
}
//swap函数
int main()
{
	MyStr a(1, "sg");
	MyStr b(2, "sg2");
	swap(a, b);
	cout << a.getId() << endl;//2
	return 0;
}

