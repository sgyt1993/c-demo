#include<iostream>
#include<string>
#include"StrBlob.h"
using namespace std;


/*int main()
{
	shared_ptr<string> p1;
	if (p1 && p1->empty()) {
		*p1 = "ni hao";
	}
	cout << *p1 << endl;
	return 0;
}*/


//shared_ptr չ�ֳ��Ķ�ָ��ָ��Ͱһ������
/*int main()
{
	StrBlob b1;
	{
		StrBlob b2 = { "a","an","the","ss" };
		b1 = b2;
		string m = "wdwd";
		b2.push_back(m);
	}
	vector<string> v1;
	{
		vector<string> v2 = { "a","an","the","ss" };
		v1 = v2;
		string m = "wdwd";
		v2.push_back(m);
	}
	cout << b1.size()<< endl;//5����������share_ptr������,�������ʹ��һ���ڴ��ַ
	cout << v1.size()<<endl;//4
	return 0;
}*/

//new
/*int main()
{
	int *p = new int(3);
	cout << *p << endl;
	delete p;//ɾ���ڴ�
	return 0;
}*/

//new  and share_ptrһ��ʹ��
/*int main()
{
	//shared_ptr<int> pi = new int(1024);����
	shared_ptr<int> p2(new int(1024));

	return 0;
}

void f()
{
	shared_ptr<int> p1(new int(10));
	int *p2 = new int(42);
	//��������׳�һ���쳣������f��δ����
	delete p2;
}//p1�ͷ����ڴ棬����p2û���Լ��ͷ��ڴ�
*/

//unique_ptr�Ĳ���
/*int main()
{
	//��Ȼunique��֧��copy������unique_ptr����ͨ��release����reset��ָ�������Ȩ��һ������const��unique_ptrת�Ƹ���һ��unique
	unique_ptr<string> p1(new string("sssss"));
	unique_ptr<string> p2(p1.release());//release��p1��Ϊ��

	//������p2����֮ǰ��ָ�룬ʹ��p3���ͷų�����ָ��
	unique_ptr<string> p3(new string("ss"));
	p2.reset(p3.release());
	return 0;
}*/\



//unique_ptr�����޳���
/*class state_deleter {
	int count;
public:
	state_deleter() :count(0) {};
	template<class T>
	void operator()(T* p) {//����Ϊʲô������������������
		cout << "[delete #" << ++count << "]\n";
		delete p;
	}
};

int main(){
	state_deleter del;
	unique_ptr<int> p;

	unique_ptr<int, state_deleter> aple(new int);
	unique_ptr<int, state_deleter> beta(new int, aple.get_deleter());
	return 0;
}*/

//operate
/*class A {
public:
	void operator()() const{
		cout << "nihao";
	}
};

int main() {
	A a;
	a();
	return 0;
}*/

//weak_ptr��ʹ��
/*int main()
{
	shared_ptr<int> sp(new int(10));
	weak_ptr<int> wp = sp;
	//weak_ptr�Ĵ�������ı�share_ptr,���ǻ��shared_ptr����������һ��
	cout << wp.use_count() << endl;;
	cout << sp.use_count() << endl;

	wp.reset();
	printf("%d\n", wp);
	return 0;
}*/


//���ʹ��shared_ptr
/*class B;
class A {
public:
	 A() { cout << "class A constructor..." << endl; };
	~ A() { cout << "class A destrictor..." << endl; };
	void show() { cout << "this A"<<endl; };
	weak_ptr<B> pb;
	shared_ptr<B> sharepb;
};
class B {
public:
	B() { cout << "class B constructor..." << endl; };
	~B() { cout << "class B destrictor..."<< endl; };
	void show() { cout << "this B" << endl; };
	weak_ptr<A> pa;
	shared_ptr<A> sharepa;
};*/


/*int main() 
{
	shared_ptr<A> spa = make_shared<A>();
	shared_ptr<B> spb = make_shared<B>();
	spa->pb = spb;
	spb->pa = spa;
	cout << spa.use_count() << endl;//1˵��û�л�������
	cout << spb.use_count() << endl;//1
	return 0;
}*/

//˵��weak_ptr�������ǲ���Ӱ��shared_ptr�ļ�����
/*int main()
{
	shared_ptr<A> spa = make_shared<A>();
	shared_ptr<B> spb = make_shared<B>();

	spa->sharepb = spb;
	spb->sharepa = spa;

	cout << spa.use_count() << endl;//2˵����
	cout << spb.use_count() << endl;//2
	return 0;
}*/

//weak_ptr��lock,expired��ʹ��
/*int  main() 
{
	shared_ptr<A> spa = make_shared<A>();
	shared_ptr<B> spb = make_shared<B>();

	cout << "spa count:" << spa.use_count() << endl;
	cout << "spb count" << spb.use_count() << endl;

	weak_ptr<A> wpa = spa;
	weak_ptr<B> wpb = spb;

	if (!wpa.expired()) {
		wpa.lock()->show();//this is A
	}

	if (!wpb.expired()) {
		wpb.lock()->show();;//this is B
	}

	spa.reset();
	spb.reset();

	if (wpa.expired()) {
		cout << "˵��weak_ptr a������shared_ptr aһ�������" << endl;
	}

	if (wpb.expired()) {
		cout << "˵��weak_ptr b������shared_ptr bһ�������" << endl;
	}

}*/










