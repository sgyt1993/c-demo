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
	int areachild = m.getArea();//���︸������ã����е�������
	cout << areachild << endl;
	Shape *c = &k;
	int areachild1 = c->getArea();//���︸������ã����е�������
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

//�������
/*class Figure 
{
protected:
	int k;
public:
	virtual void GetArea() = 0;//���麯��
};

class Circle :public Figure 
{
private:
	float m_r;
public:
	Circle(float r) :m_r(r) {};
	virtual void GetArea()  override{
		cout << "Բ�����:" << 3.14*m_r*m_r << endl;
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
		cout << "�����ε����:" << m_a * m_b / 2 << endl;
	}
};

void DisplayArea(Figure *a) 
{	
	 a->GetArea();//��ʾ��̬
}*/

/*int main() 
{
	//Figure a;������಻�ܽ�������
	Circle a(2.5f);
	Triangle t(1.2f, 2.6f);
	DisplayArea(&a);
	DisplayArea(&t);
	return 0;
}*/

//���ʿ�����̳�
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
	//c.size();��Ϊ��private,���Բ��ܷ���
	c.size2();
}*/


//���ֳ�ͻ��̳�
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
	int get_men() { return base::men; };//ʹ�����������ʹ�����صĳ�Ա
	int getmen() { return men; };//���ػ������ͬ���ֵ�����
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
	//~base() { cout << "base destructor" << endl; };//�������������
  	  virtual ~base() { cout << "base destructor" << endl; };//�ᴥ������������������������
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
//���캯���Ϳ�������
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
//�ƶ�������̳�
int main() 
{
	base a;
	base b = move(a);//base move function
	//������base�Ĺ���
	childA ac;
	childA ch = move(ac);//base move function
	return 0;
}*/

//������Ŀ������Ƴ�Ա����ʾ������������������أ�
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
	v = childb(9);//contructyor,base�ĸ�ֵ����
	cout<< v.getK()<<endl;
	return 0;
}*/
