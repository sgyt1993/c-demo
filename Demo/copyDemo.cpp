#include<iostream>
#include<string>
#include <utility> 
#include <algorithm> 
#include"DemoClass.h"
#include<vector>
#include"MyStr.h"
using namespace std;

void  getA(A c) {
	cout << "getA called\n" << endl;
}

/*int main()
{
	string  null_book = "0009999";
	string kk("9999999");
	A a(100);
	A b = a;
	b.show();
	getA(b);
	return 0;
}*/

//����ǿ�������ֵ�������İ���
/*int main() 
{

	MyStr str1(1, "swdw");
	cout << "======================" << endl;
	MyStr str2;//ʹ��Ĭ�Ϲ���
	str2 = str1;//��Ϊstr2ʹ��Ĭ�Ϲ���������Mystr��ʵ���������ø�ֵ���캯��
	cout << "=======================" << endl;
	MyStr str3 = str2;//ʹ�ÿ�������
	return 0;
}*/

//ǳ���������


//swqp����
void swap(MyStr &a, MyStr& b) {
	using std::swap;
	swap(a.id, b.id);
	swap(a.name, b.name);//��Ч�ķ�ʽ�ٴδ���һ������
}
//swap����
/*int main()
{
	MyStr a(1, "sg");
	MyStr b(2, "sg2");
	swap(a, b);
	cout << a.getId() << endl;//2
	return 0;
}*/

//�����ƶ�
/*int main() 
{
	MyStr a(1, "sg");
	MyStr b = move(a);
	cout << b.getId() << endl;
	cout << a.getId() << endl;
	return 0;
}*/

//�ƶ����캯��
/*class HasPtr{
private:
	string s;
public:

	HasPtr() :s("sgyt") {
		cout << "construct" << endl;
	};
	HasPtr(string m) {
		this->s  =  m;
		delete &m;
	};
	//����ƶ����캯��
	HasPtr(HasPtr &&p)  noexcept:s("wwddw"){
		cout << "������ƶ����캯��" << endl;
		delete &p;
	}
	//��ֵ���㺯��
	HasPtr& operator =(HasPtr rhs) {
		cout << "��ֵ�����" << endl;
		swap(*this, rhs);
		return *this;
	}
	string get() {
		return s;
	}
};

int main() 
{
	HasPtr  *a =new HasPtr;
	HasPtr b = move(*a);//HasPtr b(move(*a));Ҳ��ʹ���ƶ����캯��
	cout << b.get() << endl;
	return 0;
}*/



//���غ����ú���
/*class Foo {
private:
	vector<string> data;
public:
	Foo() = default;
	Foo(vector<string> da)
	{
		for (auto itor = da.begin(); itor != da.end(); itor++) {
			data.push_back(*itor);
		}
	};
	Foo sorted() && ;//�����ڿɸı����ֵ
	Foo sorted() const &;//�������κ����͵�Foo
};

Foo Foo::sorted() && 
{
	cout << "&&��������ֵ��" << endl;
	sort(data.begin(), data.end());
	return *this;
}
//��������const ������һ����ֵ��������������ܶ�Դֵ����
Foo Foo::sorted() const & 
{
	cout << "&��������������foo" << endl;
	//sort(data.begin(), data.end());������󡣡�����Ϊ�ǰ�const�ĺ��������Բ��ܸı�this
	Foo fo(*this);
	sort(fo.data.begin(), fo.data.end());
	return fo;
}
 
//void fun1(vector<string> vc);
int main() {
	vector<string> vc = { "s","wd","v","d","w","c","s" };
	Foo f(vc);
	move(f).sorted();
	f.sorted();
	return 0;
}*/

/*void fun1(vector<string> vc) {
	vector<string> ls;
	int zie = vc.size();
	//for(int i =0;i<vc.size();i++)����
	for (int i = 0; i < zie; i++) {
		cout << vc[i] << endl;
		ls.push_back(vc[i]);
	}
}*/