#pragma once
#include<iostream>
#include<string>
using namespace std;
//����
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
	virtual int getArea();//�麯��
	//�����е��麯����������û�б�Ҫһ����д
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
//������
class Rectangle : public Shape
{
public:
	//�����ʵ����
	int getArea()  {
		//return (priheight * width);��������е�˽�б������ʲ�����protected�ܷ��ʵ���
		cout << "this is children" << endl;
		return (proheight * width);
	};
private:
	int area;
};