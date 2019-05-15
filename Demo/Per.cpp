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


//shared_ptr 展现出的多指针指向桶一个对象
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
	cout << b1.size()<< endl;//5这里体现了share_ptr的作用,多个对象使用一个内存地址
	cout << v1.size()<<endl;//4
	return 0;
}*/

//new
/*int main()
{
	int *p = new int(3);
	cout << *p << endl;
	delete p;//删除内存
	return 0;
}*/

//new  and share_ptr一起使用
/*int main()
{
	//shared_ptr<int> pi = new int(1024);错误
	shared_ptr<int> p2(new int(1024));

	return 0;
}

void f()
{
	shared_ptr<int> p1(new int(10));
	int *p2 = new int(42);
	//这里如果抛出一个异常，且在f中未捕获，
	delete p2;
}//p1释放了内存，但是p2没有自己释放内存
*/

//unique_ptr的操作
/*int main()
{
	//虽然unique不支持copy，但是unique_ptr可以通过release或者reset将指针的所有权从一个（非const）unique_ptr转移给另一个unique
	unique_ptr<string> p1(new string("sssss"));
	unique_ptr<string> p2(p1.release());//release将p1置为空

	//这里是p2放弃之前的指针，使用p3的释放出来的指针
	unique_ptr<string> p3(new string("ss"));
	p2.reset(p3.release());
	return 0;
}*/\



//unique_ptr传递剔除器
/*class state_deleter {
	int count;
public:
	state_deleter() :count(0) {};
	template<class T>
	void operator()(T* p) {//这里为什么叫析构函数，很困惑啊
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

//weak_ptr的使用
/*int main()
{
	shared_ptr<int> sp(new int(10));
	weak_ptr<int> wp = sp;
	//weak_ptr的创建不会改变share_ptr,但是会和shared_ptr的数量保持一致
	cout << wp.use_count() << endl;;
	cout << sp.use_count() << endl;

	wp.reset();
	printf("%d\n", wp);
	return 0;
}*/


//如何使用shared_ptr
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
	cout << spa.use_count() << endl;//1说明没有互相引用
	cout << spb.use_count() << endl;//1
	return 0;
}*/

//说明weak_ptr的数量是不会影响shared_ptr的计数的
/*int main()
{
	shared_ptr<A> spa = make_shared<A>();
	shared_ptr<B> spb = make_shared<B>();

	spa->sharepb = spb;
	spb->sharepa = spa;

	cout << spa.use_count() << endl;//2说明是
	cout << spb.use_count() << endl;//2
	return 0;
}*/

//weak_ptr的lock,expired的使用
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
		cout << "说明weak_ptr a伴随着shared_ptr a一起清空了" << endl;
	}

	if (wpb.expired()) {
		cout << "说明weak_ptr b伴随着shared_ptr b一起清空了" << endl;
	}

}*/










