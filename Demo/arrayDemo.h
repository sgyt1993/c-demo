#pragma once
//�±���������
#include<iostream>
using namespace std;
class ArrayDemo {
public:
	ArrayDemo(int length = 0);
	~ArrayDemo();
	int& operator [] (int i);
	const int &operator[] (int i) const;
	int length() const { return m_length; };
	void display() const;
private:
	int m_length;//���鳤��
	int *m_p;//ָ�������ڴ��ָ��
};

ArrayDemo::ArrayDemo(int length) :m_length(length)
{
	if (length == 0) 
	{
		m_p = nullptr;
	}
	else 
	{
		m_p = new int[length];
	}
}
ArrayDemo::~ArrayDemo() 
{
	delete[] m_p;
}
int& ArrayDemo::operator[](int i)
{
	return m_p[i];
}
const int& ArrayDemo::operator[](int i) const
{
	return  m_p[i];
}
void ArrayDemo::display() const
{
	for (int i = 0; i < m_length; i++) {
		cout << m_p[i] << "   ";
	}
}