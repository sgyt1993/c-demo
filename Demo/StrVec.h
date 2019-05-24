#pragma once
#include<string>
#include<allocators>
using namespace std;
//实现的是动态内存的分配
class StrVec {
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {};
	StrVec(const StrVec &) ;//拷贝构造函数
	StrVec( StrVec &&) noexcept;//移动构造函数
	StrVec& operator = (const StrVec&);//拷贝赋值运算符
	StrVec& operator = (StrVec &&) noexcept;//移动赋值运算符
	StrVec& operator [] (size_t n);//下标运算符
	~StrVec();//析构函数
	void push_back(const string &);//拷贝函数
	void push_back(const string&&);//移动拷贝
	size_t size() const { return first_free - elements; };
	size_t capacity() const { return cap - elements; };
	string *begin() const { return elements; };
	string *end() const { return first_free; }
private:
	static  allocator<string> alloc;//分配元素
	void chk_n_alloc() { if (size() == capacity()) reallocate(); };//添加元素的函数所使用
	pair<string*, string*> alloc_n_copy(const string*, const string*);//工具函数，被拷贝构造函数，赋值运算符合析构函数所使用
	void free();//销毁元素并释放内存
	void reallocate();//获得更多内存并拷贝已有元素
	string *elements;//指向数组
	string *first_free;//指向数组第一个空闲元素的指针
	string *cap;//指向数组尾后位置的指针
};

void StrVec::push_back(const string&& s) 
{
	chk_n_alloc();//确保有空间容纳新元素
	alloc.construct(first_free++, move(s));//移动构造
}

void StrVec::push_back(const string& s) 
{
	chk_n_alloc();//确保有空间容纳新元素
	alloc.construct(first_free++, s);//在first_free指向的元素中构造s的副本
}

pair<string*, string*> StrVec::alloc_n_copy(const string* a, const string* b)
{
	auto data = alloc.allocate(b - a);//分配空间保存给定范围中的元素
	return { data,uninitialized_copy(a,b,data) };//初始化并返回一个pair,该pair由data和uninitialized_copy的返回值构成
}

void StrVec::free() 
{
	//不能传递deallocate一个空指针，如果elements为0，函数什么都不做
	if (elements) 
	{
		for (auto p = first_free; p != elements;) {
			alloc.destroy(--p);
		}
		alloc.deallocate(elements, cap - elements);
	}
}

//拷贝函数
StrVec::StrVec(const StrVec &s) {
		//调用alloc_n_copy分配空间以容纳与s中一样多的元素
	auto newdate = alloc_n_copy(s.begin(), s.end());
	elements = newdate.first;
	first_free = newdate.second;
}

//移动构造函数
StrVec::StrVec(StrVec &&s) noexcept
//成员初始化器连接s中的资源
	:elements(s.elements),first_free(s.first_free),cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;
}

StrVec::~StrVec() 
{
	free();
}

StrVec &StrVec::operator=(const StrVec &rhs) 
{
	//调用alloc_n_copy分配内存，大小与rhs相同
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = data.second;
	return *this;
}

//移动赋值运算符
StrVec & StrVec::operator=(StrVec &&rhs) {
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		//将rhs放置与折构函数中
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

//下标运算
StrVec& StrVec::operator[](size_t size) 
{
	
}

void StrVec::reallocate() 
{
	//将分配当前大小两倍的内存空间(size==0,就为false)
	auto newcapacity = size() ? 2 * size() : 1;
	//分配新的内存
	auto newdata = alloc.allocate(newcapacity);
	//将数据从旧内存移动到新内存中
	auto dest = newdata;//指向新数组中下个空闲位置
	auto elem = elements;//指向旧数组中下个元素
	for (size_t i = 0; i != size(); ++i) {
		alloc.construct(dest++, move(*elem++));
	}
	free();//完成移动元素，释放旧空间
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}