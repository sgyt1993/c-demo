#pragma once
/*使用BtrBlob 来建立一个对象，用share_ptr来管理动态分配的vector，这个share_pty的成员将记录多少个strblob共享的vector，并在最后一个使用者
销毁时释放vector*/
#include<iostream>
#include<vector>
using namespace std;
class StrBlob 
{
public:
	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(initializer_list<string> il);
	size_type size() const { return data->size(); };
	bool empty() const { return data->empty(); };
	void push_back(string &t) { data->push_back(t); };
	void pop_back();
	string &front() ;
	string &back() ;
	shared_ptr<vector<string>> data;
	//如果data[i]不合法，抛出异常
	void  check(size_type i, const string &msg) const;
};
StrBlob::StrBlob() :data(make_shared<vector<string>>()) {};
StrBlob::StrBlob(initializer_list<string> il) :data(make_shared<vector<string>>(il)) {};
void StrBlob::check(size_type i, const string &msg) const
{
	if (i >= data->size()) 
	{
		throw out_of_range(msg);
	}
}

string& StrBlob::front() 
{
	check(0, "front on empty StrBlob");
	return data->front();
}
string& StrBlob::back() 
{
	check(0, "back on empty StrBlob");
	return data->back();
}
void StrBlob::pop_back() 
{
	check(0, "pop_back on empty StrBlob");
	return data->pop_back();
}
