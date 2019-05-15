#pragma once
#include<iostream>
#include<string>
#include<set>
using namespace std;
class Folder;
class Message {
	friend class Folder;
public:
	explicit Message(const string &str = "") :contents(str) {};//folders被隐式的初始化为空集合
	Message(const Message&);//拷贝构造函数
	Message& operator = (const Message&);//拷贝赋值运算符
	~Message() { remove_from_Folders(); };//析构函数
	void save(Folder&);
	void remove(Folder &);
private:
	string contents;//实际消息文本
	set<Folder*> folders;//包含本Message的Folder
	void add_to_Folders(const Message&);//将本Message添加到Folders中
	void remove_from_Folders();//在folders中的每个message删除
};

void Message::save(Folder& f) {
	folders.insert(&f);	
	f.addMsg(this);
}
void Message::remove(Folder& f) {
	folders.erase(&f);
	f.remMsg(this);
}
void Message::add_to_Folders(const Message& m) {

}
void Message::remove_from_Folders() {
	
}


class Folder {
public:
	void addMsg( Message *);
	void remMsg(Message *);
};