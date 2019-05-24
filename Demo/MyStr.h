#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class MyStr {
	friend void swap(MyStr &, MyStr &);//定义swap的友好类，主要放swap能访问MyStr的private属性
private:
	char *name;
	int id;
public:
	MyStr() {};
	MyStr(int _id,const char *_name) //constructor
	{
		cout << "constructor" << endl;
		id = _id;
		name = new char[strlen(_name) + 1];
		strcpy_s(name, strlen(_name) + 1, _name);
	};
	MyStr(const MyStr& str)//拷贝赋值函数
	{
		cout << "copy constructor" << endl;
		id = str.id;
		if (name != NULL) 
		{
			delete[] name;
		}
		name = new char[strlen(str.name) + 1];
		strcpy_s(name, strlen(str.name) + 1, str.name);
	};
	MyStr(MyStr&& str):name(str.name),id(str.id)//移动赋值函数
	{
		cout << "移动赋值函数" << endl;
		delete &str;
	};
	MyStr& operator = (const MyStr& str)//赋值运算
	{
		cout << "operator =" << endl;
		if (this != &str) 
		{
			if (name != NULL) 
			{
				delete[] name;
				name = new char[strlen(str.name) + 1];
				strcpy_s(name, strlen(str.name) + 1, str.name);
			}
		}
		return *this;
	};

	~MyStr() //析构函数
	{
		cout << "constructor destry" << endl;
		delete[] name;
	};

	int getId() {
		return this->id;
	}
};


