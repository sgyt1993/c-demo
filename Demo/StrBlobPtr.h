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
	StrBlobPtr& incr();//ǰ׺����
private:
	//������ɹ���check����һ��ָ��vector��shared_ptr
	shared_ptr<vector<string>> check(size_t, const string&) const;
	//����һ��weak_ptr,��ζ�ŵײ�vector�ᱻ����
	weak_ptr<vector<string>> wptr;
	//�������еĵ�ǰλ��
	size_t curr;
};