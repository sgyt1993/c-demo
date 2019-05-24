#include<iostream>
#include<string>
#include"OOPdemo.h"
using namespace std;

/*int main() 
{
	Rectangle k;
	k.setproHeight(10);
	k.setWidth(10);
	Shape &m = k;
	int areachild = m.getArea();//这里父类的引用，所有调用子类
	cout << areachild << endl;
	Shape *c = &k;
	int areachild1 = c->getArea();//这里父类的引用，所有调用子类
	cout << areachild1 << endl;
	return 0;
}*/


/*class A {
public:
	A() = default;
	A(int c) {
		a = c;
	};
	static int a ;
	int get() {
		return a;
	};
	virtual void pri() { cout << "A function" << endl; }
};
int A::a = 0;
class B :public A {
public:
	B()= default;
	int add() {
		a++;
		return a;
	}
	void pri() override{ cout << "B function" << endl; }
};

class C :public A {
public:
	C()= default;
	int add() {
		a++;
		return a;
	}
	void pri() override { cout<<"C function"<<endl; }
};*/
/*int main()
{
	A a(3);
	cout << a.get() << endl;
	B b;
	b.add();
	cout << a.get() << endl;
	return 0;
}*/

//抽象基类
/*class Figure 
{
protected:
	int k;
public:
	virtual void GetArea() = 0;//纯虚函数
};

class Circle :public Figure 
{
private:
	float m_r;
public:
	Circle(float r) :m_r(r) {};
	virtual void GetArea()  override{
		cout << "圆的面积:" << 3.14*m_r*m_r << endl;
	};
};

class Triangle :public Figure 
{
private:
	float m_a;
	float m_b;
public:
	Triangle(float m_a, float m_b) :m_a(m_a), m_b(m_b) {};
	virtual void GetArea()  override
	{
		cout << "三角形的面积:" << m_a * m_b / 2 << endl;
	}
};

void DisplayArea(Figure *a) 
{	
	 a->GetArea();//显示多态
}*/

/*int main() 
{
	//Figure a;抽象基类不能建立对象
	Circle a(2.5f);
	Triangle t(1.2f, 2.6f);
	DisplayArea(&a);
	DisplayArea(&t);
	return 0;
}*/

//访问控制与继承
/*class base 
{
public:
	int size() { return k; }
	int size2() { return k; }
protected:
	int k = 0;
};

class child :private base
{
public:
	using base::size2;
	child() = default;
	void pri() { cout << k << endl; }
};*/

/*int main() {
	child c;
	c.pri();
	//c.size();因为是private,所以不能访问
	c.size2();
}*/


//名字冲突与继承
/*struct  base 
{
	base() :men(0) {};
protected:
	int men;
};

struct Derived :public base 
{
	Derived() = default;
	Derived(int i) :men(i) {};
	int get_men() { return base::men; };//使用域运算符来使用隐藏的成员
	int getmen() { return men; };//隐藏基类的相同名字的属性
protected:
	int men;
};*/

/*int main() 
{
	Derived d(8);
	cout << d.getmen() << endl;//8
	cout << d.get_men() << endl;//0
	return 0;
}*/

/*class base {
public:
	base() = default;
	//~base() { cout << "base destructor" << endl; };//触发基类的析构
  	  virtual ~base() { cout << "base destructor" << endl; };//会触发基类的析构，派生类的析构
private:
	int a, b;
};

class child :public base 
{
public:
	child() = default;
	~child() 
	{ 
		cout << "child destructor" << endl;
		if (pi != nullptr) {
			delete pi;
		}
	}
private:
	int *pi;
};
//构造函数和拷贝控制
int main()
{
	
	child *d =  new child;
	base *b = d;
	//delete b;
	delete b;
	return 0;
}*/

/*class base {
public:
	base() = default;
	base(base&& b) {
		cout<< "base move function" << endl;
	};
	base& operator = (base &&) 
	{
		cout << "base move function" << endl;
	}
};

class childA :public base 
{
public:
	childA() = default;
private:
	int a, b;
};
//移动操作与继承
int main() 
{
	base a;
	base b = move(a);//base move function
	//重载了base的构造
	childA ac;
	childA ch = move(ac);//base move function
	return 0;
}*/

//派生类的拷贝控制成员（显示定义派生类的运算重载）
/*class base {
public:
	base() = default;
	base(int age) { this->age = age; }
	base& operator = (const base &b) {
		cout << "base operator" << endl;
		this->age = b.age;
		return *this;
	}
	void setAge(int age) { this->age = age; }
	int getAge() { return age; };
private:
	int age;
};
class childb :public base 
{
public:
	childb() = default;
	explicit childb(int k) { 
		cout << "contructyor" << endl;
		this->k = k; 
	};
	
	int getK() { return k; };
private:
	int k;
};
int main()
{
	childb v;
	v = childb(9);//contructyor,base的赋值调用
	cout<< v.getK()<<endl;
	return 0;
}*/
