#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//�ع����������
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


//������������<<
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
	//��������ģ������
	OperatorStream a(1, "sgyt", 26);
	cout << a << endl;//1    sgyt   26
	OperatorStream b;
	cin >> b;//2   sg  28
	cout << b;//2   sg  28

	//�ļ����룬���
	ofstream  ws("e:/sgyt.txt",ios::out);
	if (ws.fail()) {
		cout << "���ļ�ʧ��" << endl;
		exit(0);
	}
	ws << a << endl;
	OperatorStream ord;
	ifstream rd("e:/sgyt.txt");
	rd >> ord;
	cout <<"ord:"<< ord;//1    sgyt   26
	return 0;
}*/


//�±������
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


//��Ա���������
/*#include"ObjectOverLoad.h"
int main()
{
	operatorDemo a("sss");
	cout << a->size() << endl;
	return 0;
}*/

//�������������
/*class abInt 
{
private:
	int s;
public:
	abInt() :s(2) {};
	abInt(int k) //��ʼ��
	{
		this->s = k;
	};
	int operator()(int val)//���õ������
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

//��׼���еĺ�������
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
		cout << "����ת��" << endl;
		return k;
	}
private:
	int k;
	string m;
};

//��������ת��
int  main()
{
	DemoStr s(1221);
	//int m = int(s);
	//DemoStr sl = 5;//��������ʾת��
	//int o = s;//������ת������������ʽת��
	int add = s + 3;//�Ƚ�sת��Ϊint,�ڽ��мӼ���
	//cout << m << endl;
	cout << add << endl;
	//cout << sl << endl;
	return 0;
}*/


//�����ж����Ե�����ת��
//����ƥ�������������
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
		��һ���ӷ������ʹ��operator+�ķ�������Ψһ��
		�ڶ�����������ַ��룺
				1.��4ת����SmallInt,Ȼ��ʹ��SmallInt��operator+
				2.��s3ת����int,Ȼ��������intִ�����õļӷ�����
	*/
	/*int  main()
{
	SmallInt s1, s2;
	SmallInt s3 = s1 + s2;//ʹ�õ���operator+
	//int i = s3 + 4;//���������⣬
}*/
