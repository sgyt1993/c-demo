#pragma once
#include<string>
#include"StrBlob.h"
using namespace std;
class StrBlobPtr
{
public:
	StrBlobPtr() :curr(0) {};
	StrBlobPtr(StrBlob &a, size_t sz = 0) :wptr(a.data), curr(sz) {};
	string& derdf() const;
	StrBlobPtr& incr();//前缀递增
private:
	//如果检查成功，check返回一个指向vector的shared_ptr
	shared_ptr<vector<string>> check(size_t, const string&) const;
	//保存一个weak_ptr,意味着底层vector会被销毁
	weak_ptr<vector<string>> wptr;
	//在数组中的当前位置
	size_t curr;
};