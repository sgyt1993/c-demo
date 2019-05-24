#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class MyStr {
	friend void swap(MyStr &, MyStr &);//����swap���Ѻ��࣬��Ҫ��swap�ܷ���MyStr��private����
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
	MyStr(const MyStr& str)//������ֵ����
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
	MyStr(MyStr&& str):name(str.name),id(str.id)//�ƶ���ֵ����
	{
		cout << "�ƶ���ֵ����" << endl;
		delete &str;
	};
	MyStr& operator = (const MyStr& str)//��ֵ����
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

	~MyStr() //��������
	{
		cout << "constructor destry" << endl;
		delete[] name;
	};

	int getId() {
		return this->id;
	}
};


