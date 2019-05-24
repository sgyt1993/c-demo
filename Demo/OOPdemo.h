#pragma once
#include<iostream>
#include<string>
using namespace std;
//基类
class Shape {
public:
	void setWidth(int w) {
		width = w;
	};
	void setpriHeight(int h) {
		priheight = h;
	};
	void setproHeight(int h) {
		proheight = h;
	};
	virtual int getArea();//虚函数
	//基类中的虚函数数，子类没有必要一定重写
	virtual int getArea1()
	{
		return 99;
	};
protected:
	int width;
	int proheight;
private:
	int priheight;
};
int Shape::getArea()
{
	cout << "this is parent" << endl;
	return 0;
}
//派生类
class Rectangle : public Shape
{
public:
	//这个是实现类
	int getArea()  {
		//return (priheight * width);这里对象中的私有变量访问不到，protected能访问到；
		cout << "this is children" << endl;
		return (proheight * width);
	};
private:
	int area;
};