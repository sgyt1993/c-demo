#pragma once
#include<iostream>
#include<string>
#include<set>
using namespace std;
class Quote {
public:
	Quote() = default;
	Quote(const string &book, double sales_price) :bookNo(book), price(sales_price) {};
	//book��isbn�ı��
	string isbn() { return bookNo; }
	//�����鼮��ʱ�����ۼܹ������û��ﵽ������������ʱ 
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
	//���ݴ����item�βεĶ������͵���quote::net_price
	double ret = item.net_price(n);
	os << "ISBN" << item.isbn() << "#sold:" << n << "total due:" << ret << endl;
}

//��ʾ����������
class Basket 
{
public:
	//Basketʹ�úϳɵ�Ĭ�Ϲ��캯���Ϳ�������
	void add_item(const shared_ptr<Quote> &sale) { item.insert(sale); }
	//��ӡÿ������ټ��͹���������������ܼ�
	double total_receipt(ostream &) const;
private:
	//���ڱȽ�shared_ptr��multiser��Ա���õ���
	static bool	compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs) 
	{
		return lhs->isbn() < rhs->isbn();
	}

	//multiset���������ۣ���װcompare��Ա����
	multiset<shared_ptr<Quote>, decltype(compare)*> item{ compare };
};

double Basket::total_receipt(ostream &os) const
{
	//����ʵʱ��������ܼ۸�
	double sum = 0.0;
	//iterָ��ISBN��ͬ��һ��Ԫ���еĵ�һ��
	//upper_bound����һ�����������õ�����ָ������Ԫ��β��λ��
	for (auto iter = item.cbegin(); iter != item.cend(); iter = item.upper_bound(*iter))
	{
		//֪���ڵ�ǰ��Basket��������һ���Ĺؼ��ֵ�Ԫ��
		//��ӡ�����ݶ�Ӧ����Ŀ
		sum += print_total(os, **iter, item.count(*iter));

	}
	os << "Total Sale:" << sum << endl;//��ӡ���յ��ܼ۸�
	return sum;
}