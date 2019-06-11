#pragma once
#include<iostream>
using namespace std;
extern char  st[];
class Base 
{
public:
	Base() =default;
	virtual void Show() { cout << "this is base class"<<endl; }
};
class Dervied :public Base
{
public:
	Dervied() = default;
	void Show()  override { cout << "this is Dervied class"<<endl; }
};

