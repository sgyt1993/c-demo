#pragma once
#include<iostream>
#include<string>
#include<set>
using namespace std;
class Folder;
class Message {
	friend class Folder;
public:
	explicit Message(const string &str = "") :contents(str) {};//folders����ʽ�ĳ�ʼ��Ϊ�ռ���
	Message(const Message&);//�������캯��
	Message& operator = (const Message&);//������ֵ�����
	~Message() { remove_from_Folders(); };//��������
	void save(Folder&);
	void remove(Folder &);
private:
	string contents;//ʵ����Ϣ�ı�
	set<Folder*> folders;//������Message��Folder
	void add_to_Folders(const Message&);//����Message��ӵ�Folders��
	void remove_from_Folders();//��folders�е�ÿ��messageɾ��
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