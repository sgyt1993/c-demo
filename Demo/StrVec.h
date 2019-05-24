#pragma once
#include<string>
#include<allocators>
using namespace std;
//ʵ�ֵ��Ƕ�̬�ڴ�ķ���
class StrVec {
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {};
	StrVec(const StrVec &) ;//�������캯��
	StrVec( StrVec &&) noexcept;//�ƶ����캯��
	StrVec& operator = (const StrVec&);//������ֵ�����
	StrVec& operator = (StrVec &&) noexcept;//�ƶ���ֵ�����
	StrVec& operator [] (size_t n);//�±������
	~StrVec();//��������
	void push_back(const string &);//��������
	void push_back(const string&&);//�ƶ�����
	size_t size() const { return first_free - elements; };
	size_t capacity() const { return cap - elements; };
	string *begin() const { return elements; };
	string *end() const { return first_free; }
private:
	static  allocator<string> alloc;//����Ԫ��
	void chk_n_alloc() { if (size() == capacity()) reallocate(); };//���Ԫ�صĺ�����ʹ��
	pair<string*, string*> alloc_n_copy(const string*, const string*);//���ߺ��������������캯������ֵ�����������������ʹ��
	void free();//����Ԫ�ز��ͷ��ڴ�
	void reallocate();//��ø����ڴ沢��������Ԫ��
	string *elements;//ָ������
	string *first_free;//ָ�������һ������Ԫ�ص�ָ��
	string *cap;//ָ������β��λ�õ�ָ��
};

void StrVec::push_back(const string&& s) 
{
	chk_n_alloc();//ȷ���пռ�������Ԫ��
	alloc.construct(first_free++, move(s));//�ƶ�����
}

void StrVec::push_back(const string& s) 
{
	chk_n_alloc();//ȷ���пռ�������Ԫ��
	alloc.construct(first_free++, s);//��first_freeָ���Ԫ���й���s�ĸ���
}

pair<string*, string*> StrVec::alloc_n_copy(const string* a, const string* b)
{
	auto data = alloc.allocate(b - a);//����ռ䱣�������Χ�е�Ԫ��
	return { data,uninitialized_copy(a,b,data) };//��ʼ��������һ��pair,��pair��data��uninitialized_copy�ķ���ֵ����
}

void StrVec::free() 
{
	//���ܴ���deallocateһ����ָ�룬���elementsΪ0������ʲô������
	if (elements) 
	{
		for (auto p = first_free; p != elements;) {
			alloc.destroy(--p);
		}
		alloc.deallocate(elements, cap - elements);
	}
}

//��������
StrVec::StrVec(const StrVec &s) {
		//����alloc_n_copy����ռ���������s��һ�����Ԫ��
	auto newdate = alloc_n_copy(s.begin(), s.end());
	elements = newdate.first;
	first_free = newdate.second;
}

//�ƶ����캯��
StrVec::StrVec(StrVec &&s) noexcept
//��Ա��ʼ��������s�е���Դ
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
	//����alloc_n_copy�����ڴ棬��С��rhs��ͬ
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = data.second;
	return *this;
}

//�ƶ���ֵ�����
StrVec & StrVec::operator=(StrVec &&rhs) {
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		//��rhs�������۹�������
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

//�±�����
StrVec& StrVec::operator[](size_t size) 
{
	
}

void StrVec::reallocate() 
{
	//�����䵱ǰ��С�������ڴ�ռ�(size==0,��Ϊfalse)
	auto newcapacity = size() ? 2 * size() : 1;
	//�����µ��ڴ�
	auto newdata = alloc.allocate(newcapacity);
	//�����ݴӾ��ڴ��ƶ������ڴ���
	auto dest = newdata;//ָ�����������¸�����λ��
	auto elem = elements;//ָ����������¸�Ԫ��
	for (size_t i = 0; i != size(); ++i) {
		alloc.construct(dest++, move(*elem++));
	}
	free();//����ƶ�Ԫ�أ��ͷžɿռ�
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}