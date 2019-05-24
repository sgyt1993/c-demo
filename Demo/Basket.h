#pragma once
#include<iostream>
#include<string>
#include<set>
using namespace std;
class Quote {
public:
	Quote() = default;
	Quote(const string &book, double sales_price) :bookNo(book), price(sales_price) {};
	//book的isbn的编号
	string isbn() { return bookNo; }
	//返回书籍的时间销售架构，当用户达到购买该书的数量时 
	double net_price(int n) const { return n * price; }
	virtual ~Quote() = default;
private:
	string bookNo;
	int isbn;
protected:
	double price = 0.0;
};
double print_total(ostream &os, Quote &item,size_t n)
{
	//根据传入的item形参的对象类型调用quote::net_price
	double ret = item.net_price(n);
	os << "ISBN" << item.isbn() << "#sold:" << n << "total due:" << ret << endl;
}

//表示购物篮的类
class Basket 
{
public:
	//Basket使用合成的默认构造函数和拷贝函数
	void add_item(const shared_ptr<Quote> &sale) { item.insert(sale); }
	//打印每本书的踪迹和购物篮中所有书的总价
	double total_receipt(ostream &) const;
private:
	//用于比较shared_ptr，multiser成员会用到它
	static bool	compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs) 
	{
		return lhs->isbn() < rhs->isbn();
	}

	//multiset保存多个报价，安装compare成员排序
	multiset<shared_ptr<Quote>, decltype(compare)*> item{ compare };
};

double Basket::total_receipt(ostream &os) const
{
	//保存实时计算出的总价格
	double sum = 0.0;
	//iter指向ISBN相同的一批元素中的第一个
	//upper_bound返回一个迭代器，该迭代器指向这批元素尾后位置
	for (auto iter = item.cbegin(); iter != item.cend(); iter = item.upper_bound(*iter))
	{
		//知道在当前的Basket中至少有一个改关键字的元素
		//打印改数据对应的项目
		sum += print_total(os, **iter, item.count(*iter));

	}
	os << "Total Sale:" << sum << endl;//打印最终的总价格
	return sum;
}