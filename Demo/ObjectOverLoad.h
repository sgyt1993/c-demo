#pragma once
#include<iostream>
#include<vector>
using namespace std;

//ʵ����
class operatorDemo {
public:
	operatorDemo() = default;
	operatorDemo(string n) { this->s = n; };
	string* operator ->() 
	{
		//string *k = &s;
		return  &s;
	}
private:
	string s;
};