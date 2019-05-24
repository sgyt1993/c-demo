#include<iostream>
#include<string>
#include <utility> 
#include <algorithm> 
#include"DemoClass.h"
#include<vector>
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
/*int main()
{
	MyStr a(1, "sg");
	MyStr b(2, "sg2");
	swap(a, b);
	cout << a.getId() << endl;//2
	return 0;
}*/

//对象移动
/*int main() 
{
	MyStr a(1, "sg");
	MyStr b = move(a);
	cout << b.getId() << endl;
	cout << a.getId() << endl;
	return 0;
}*/

//移动构造函数
/*class HasPtr{
private:
	string s;
public:

	HasPtr() :s("sgyt") {
		cout << "construct" << endl;
	};
	HasPtr(string m) {
		this->s  =  m;
		delete &m;
	};
	//添加移动构造函数
	HasPtr(HasPtr &&p)  noexcept:s("wwddw"){
		cout << "这个是移动构造函数" << endl;
		delete &p;
	}
	//赋值运算函数
	HasPtr& operator =(HasPtr rhs) {
		cout << "赋值运算符" << endl;
		swap(*this, rhs);
		return *this;
	}
	string get() {
		return s;
	}
};

int main() 
{
	HasPtr  *a =new HasPtr;
	HasPtr b = move(*a);//HasPtr b(move(*a));也是使用移动构造函数
	cout << b.get() << endl;
	return 0;
}*/



//重载和引用函数
/*class Foo {
private:
	vector<string> data;
public:
	Foo() = default;
	Foo(vector<string> da)
	{
		for (auto itor = da.begin(); itor != da.end(); itor++) {
			data.push_back(*itor);
		}
	};
	Foo sorted() && ;//可用于可改变的右值
	Foo sorted() const &;//可用于任何类型的Foo
};

Foo Foo::sorted() && 
{
	cout << "&&方法给右值用" << endl;
	sort(data.begin(), data.end());
	return *this;
}
//本对象是const 或者是一个左值，那种情况都不能对源值排序
Foo Foo::sorted() const & 
{
	cout << "&方法，适用所有foo" << endl;
	//sort(data.begin(), data.end());编译错误。。。因为是吧const的函数，所以不能改变this
	Foo fo(*this);
	sort(fo.data.begin(), fo.data.end());
	return fo;
}
 
//void fun1(vector<string> vc);
int main() {
	vector<string> vc = { "s","wd","v","d","w","c","s" };
	Foo f(vc);
	move(f).sorted();
	f.sorted();
	return 0;
}*/

/*void fun1(vector<string> vc) {
	vector<string> ls;
	int zie = vc.size();
	//for(int i =0;i<vc.size();i++)错误
	for (int i = 0; i < zie; i++) {
		cout << vc[i] << endl;
		ls.push_back(vc[i]);
	}
}*/