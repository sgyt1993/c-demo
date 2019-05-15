#pragma once
#include<iostream>
using namespace std;
class  A {
public:
	A();
	A(int b)
	{
		a = b;
		printf("constructor is called\n");
	}
	A(const A& c) {
		a = c.a;
		printf("copy constructor is called\n");
	};
	~A()
	{
		printf("destructor is called\n");
	};
	void show()
	{
		cout << a << endl;
	}
private:
	int a;
};