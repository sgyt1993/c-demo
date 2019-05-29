#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
template<typename T>class Blob 
{
public:
	typedef T value_type;
	typedef typename vector<T>::size_type size_type;

	//���캯��
	Blob() =default;
	Blob(initializer_list<T> il) {
		//data = make_shared<vector<T>>(new vector<T>);����ֱ��д��dataû�г�ʼ����ַ
		data.reset(new vector<T>);
		data->insert(data->begin(),il.begin(), il.end());
		/*for (auto iter = il.begin(); iter != il.end(); iter++)
		{
			data->push_back(*iter);
		}*/
	};

	//��ģ��ĳ�Աģ��
	template<typename ti> Blob(ti a, ti b) {
		data.reset(new vector<T>);
		data->insert(data->begin(),a, b);
	}

	//Blob�е�Ԫ������
	size_type size() const { return data->size(); };
	bool empty() const { return data->empty(); };

	//��Ӻ�ɾ��Ԫ��
	void push_back(const T &t) {
		data->push_back(t);
	};
	void push_back(T &&t) 
	{
		 data->push_back(std::move(t));
	}
	void pop_back() { data->pop_back(); };

	//Ԫ�ط���
	T& back() {
		return data->back();
	};
	T& operator[](size_type i) {
		return data->at(i);
	};

private:
	shared_ptr<vector<T>> data;
	//��data[i]��Ч�����׳�msg
	void check(size_type i, const string &msg) const {
		size_type count = data->size();
		if (count < i) {
			throw std::out_of_range(msg);
		}
	};
};
