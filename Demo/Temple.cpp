#include<iostream>
#include<sstream>
#include<string>
using namespace std;

//����ģ������
template<typename T> int compare(const T& v1, const T& v2) 
{
	if (v1 > v2) 
	{
		return -1;
	}
	else 
	{
		return 1;
	}
}

/*int main() 
{
	auto k = compare(10, 9);
	cout << k << endl;
	return 0;
}*/
/*#include<vector>
int main() 
{

	string s = "sdwdw";
	string k(std::move(s));
	cout << k << endl;//sdwdw
	cout << s << endl;
	int i = 3;
	int m(move(i));
	cout << i << endl;//3
	cout << m << endl;//3
	return 0;
}*/

/*#include"Blob.h"
int main()
{
	Blob<int> bo = { 1,2,3,4,45,5 };
	bo.push_back(6);
	cout<<bo.size()<<endl;
	 shared_ptr<string> ss = make_shared<string>("wdwd");
	// shared_ptr<string> ss = make_shared<string>(new string("wdwd"));���󣬱�������һ��ָ��
	 shared_ptr<string> ss1;
	 ss1.reset(new string("sss"));
	cout << *ss << endl;
	cout << *ss1 << endl;
	return 0;
}*/

//ģ�����
/*template<typename T, typename F = less<T>> int  compare(const T &v1, const T &v2, F f = F()) 
{
	if (f(v1, v2)) 
	{ 
		return 1;
	};
	if (f(v2, v1)) 
	{
		return -1;
	};
	return 0;
}

int main() 
{
	bool f = compare(1, 2, [](int a, int b) {return a > b; });
	cout << f << endl;
}*/

//Ĭ��ģ�����
/*template<class T = int> class Numbers //TĬ��Ϊint
{
public:
	Numbers(T t) :val(t) {}
	T get() { return val; }
private:
	T val;
};
int main() 
{	
	Numbers<int> n(5);
	Numbers<string> n1("sdsd");
	Numbers<> n3(3);//����Ĭ������Ϊint
	cout << n.get() << endl;
	cout << n1.get() << endl;
	cout << n3.get() << endl;
	return 0;
}*/

//��Աģ��
/*class DebugDelete 
{
public:
	DebugDelete(ostream& s = cerr) :os(s) {};
	//���κκ���ģ����ͬ��T�������ɱ�������Ƴ�
	template<typename T>void operator()(T *p) const 
	{
		cout << "delete unique_ptr" << endl;
		delete p;
	}
private:
	ostream &os;
};
int main() 
{
	double* p = new double;
	DebugDelete d;//����delete���ʽһ��ʹ�ö���
	d(p);
	int* pi = new int;
	DebugDelete()(pi);
	return 0;
}*/

/*#include"Blob.h"
int main()
{
	int ia[] = { 1,2,34,343,45,4,4,5 };
	Blob<int> b(begin(ia),end(ia));
	cout << b.size() << endl;
	return 0;
}*/


//����ʵ����
//#include"Blob.h"
//��ģ������ڳ�������λ�ý���ʵ��������С���ļ���ʵ��ģ�忪��
/*extern template class Blob<string>;
int main() 
{
	Blob<string> sa1, sa2;//ʵ���������������λ��
	Blob<int> a1 = { 1,2,3,4,5,5,6,767,43 };//�ڱ��ļ���ʵ����
	Blob<int> a2(a1);//�ڱ��ļ���ʵ����
	return 0;
}*/

//Ч���������


//ģ��ʵ���ƶ�
/*template<typename T>T  fo(T, T);
template<typename T>T  fr(const T &, const T &);

int main() 
{
	string s2("ddw");
	const string s1("cwd");
	fo(s2, s1);
	fr(s2, s1);//const ���ͻ��Զ�ת��

	int a[10], b[22];
	fo(a, b);
	//����fr(a, b);//���Ͳ�ƥ�䣬��int a[10]��ת��Ϊint*�������Ͳ���
	return 0;
}*/

//����ģ����ʾʵ��
 
 /*template<typename T> 
 auto get(T t, T b) ->decltype(*t)//��������
 {
	 return *t;
 }*/

//����ָ��
//template<typename T> int compare(const T&, const T&);
//pf1ָ��ʵ��int compare
//int(*pf1)(const int&, const int&) = compare;


//ģ��ʵ���ƶϺ�����
/*struct A 
{
	A(int&& n) 
	{
		cout << "rvalue overlad ,n =" << n << endl;
	}

	A(int& n) 
	{
		cout << "lvalue overload,n=" << n << endl;
	}

};
struct B 
{
	template<typename T1, class T2, class T3>  B(T1&& t1, T2&& t2, T3&& t3):
		a1(forward<T1>(t1)),
		a2(forward<T2>(t2)),
		a3(forward<T3>(t3))
	
	{};
	A a1, a2, a3;
};

template<typename T, class U> unique_ptr<T> make_unique2(U&& u) 
{
	return unique_ptr<T>(new T(move(u)));
}

template<typename T, class U> unique_ptr<T> make_unique1(U&& u)
{

	return unique_ptr<T>(new T(forward<U>(u)));
	//return unique_ptr<T>(new T(forward<T>(u)));//����д���˲����������������ֵ��ţ��
}

int main() 
{
	int i = 100;
	auto p1 = make_unique2<A>(2);//rvalue overlad
	auto p2 = make_unique2<A>(i);//rvalue overlad
	cout << "..................................." << endl;
	int c = 20;
	auto p3 = make_unique1<A>(2);//rvalue overload�������
	auto p4 = make_unique1<A>(c);//lvalue overload
	cout << "..................................." << endl;
	int j = 3;
	int k = 5;
	auto p5 = make_unique<B>(k, 2, j);
	//lvalue overload 5
	//rvalue overlad 2
	//lvalue overload 3
	return 0;
}*/
/*void g(int &&i, int& k) {
	cout << i <<"     "<< k << endl;
}
template<typename F, typename T1, typename T2> void  filed1(F f, T1&& t1, T2&& t2) {
	f(forward<T1>(t1), forward<T2>(t2));
	//f(t1, t2);��ֵ����ֱ�Ӹ�ֵ����ֵ
}
int main() 
{
	int i = 4;
	filed1(g,3, i);
}*/




//������ģ��
/*template<typename T>string debug_rep(const T &t) 
{
	ostringstream r;
	r << t;
	return r.str();
}

template<typename T>string debug_rep(T *p) 
{
	ostringstream r;
	r << "pointer:" << p;
	if (p) 
	{
		r << "" << debug_rep(*p);
	}
	else {
		r << "null pointer";
	}
	return r.str();
}
int  main()
{
	string s("dwdw");
	string *k = new string("sdw");
	cout << debug_rep(s) << endl;
	cout << debug_rep(k) << endl;
	return 0;
}*/

//Args��һ��ģ���������rest��һ������������
//Args��ʾ�������ģ�����Ͳ���
//rest��ʾ���������������
/*template<typename T, typename... Args> 
void foo(const T& t,const Args&... rest) 
{
	
}
//�ɱ����ģ��
int main()
{
	foo(1, 34, 34, 343, "wdw", "dwd");
	return 0;
}*/

//ģ�����Ա������
/*template<typename T>struct  doo 
{
	doo(const T& t) :men(t) {};
	void Bar() {
		cout << "T bar" << endl;
	};
	T men;
};

template<>
void doo<int>::Bar() {
	cout << "int bar" << endl;
};
int main() 
{
	doo<string> n("dwd");
	n.Bar();//T bar
	doo<int> s(3);
	s.Bar();//int bar
	doo<long> k(22l);
	k.Bar();//T bar
	return 0;
}*/