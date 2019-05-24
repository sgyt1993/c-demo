//��̬����
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<map>
#include<set>
using  namespace std;

/*class A {
public:
	A() :k(0) {};
	A(int i) {
		this->k = i;
	}
	void show() { cout << k << endl; };
private:
	int k;
};

//��ʼ����̬����
void  construction() 
{
	int *pia = new int[10];//10��δ��ʼ����int 
	int *pia2 = new int[10]();//10��ֵ��ʼ��Ϊ0��int
	string *psa = new string[10];//10���յ�string
	string *psa2 = new string[10]();//10���յ�string
	int  *pia3 = new int[10]{ 0,1,2,3,4,5 };
}

//ɾ����̬����
void deletedemo() {
	int  *pi = new int[10];
	delete[] pi;//������[]ɾ����̬������
	
	unique_ptr<int[]> up(new int[10]);
	up.release();//�Զ��ص���delete[]��������
}

//allocator��
void demo()
{
	allocator<A> alloc;//����һ�����Է����string��allocator����
	A* k = alloc.allocate(10);//����n����ʼ����string�ڴ棬��Ȼֻ��ԭʼ�ڴ棬Ϊ����
	auto q = k;
	alloc.construct(k);//ʹ��Ĭ�Ϲ���
	alloc.construct(k + 1, 2);
	alloc.construct(k + 3, 5);
	k->show();//0
	(k + 1)->show();//2
	(k + 2)->show();//����һ����ֵַ
	(k + 3)->show();//5
	

}

class TextQuery {
public:
	TextQuery();
	TextQuery(string str) {
		ifstream io(str, ios::app);
		int lineNum = 1;
		if (io.fail()) {
			cout << "�ļ���ʧ��" << endl;
			exit(0);
		}
		string line,word;//����ÿһ�е�����,ÿ���е�����
		while (getline(io, line)) {
			set<string> *s = new set<string>;
			istringstream rec(line);//��ÿһ�����ݱ��浽istringstream,
			while (rec >> word) {
				//ѭ���а�ÿ�����ʷŵ�������
				s->insert(word);
			}
			mp.insert({ lineNum, *s });
			//ɾ��s�Ŀռ�
			delete s;
			lineNum++;
		}
		io.close();
	};
	void show();
	map<int, set<string>> getall() { return mp; };
	void check() {};
	vector<int> query(string s);
private:
	shared_ptr<ifstream> ki;
	vector<string> vc;
	map<int, set<string>>  mp;
};
//չ�����еĶ���������
void TextQuery::show() 
{
	for (auto m = mp.begin(); m != mp.end(); m++) {
		cout << m->first << endl;
		set<string> s = m->second;
		for (string st : s) {
			cout << st<<"     ";
		}
		cout << "\n";
	}
}
//��ѯ����ַ��ڵڼ���
vector<int>  TextQuery::query(string str)
{
	vector<int> *vc = new vector<int>;
	for (auto m = mp.begin(); m != mp.end(); m++) {
		set<string> s = m->second;
		for (string st : s) {
			if (st == str) {
				vc->push_back(m->first);
				continue;
			}
		}
		
	}
	return *vc;
}

//�ı���ѯ����
void  runQueryies() 
{
	//��ӡ�������ݲ��ڵڼ���
	//TextQuery *tx = new TextQuery("e:/sgyt.txt");
	//tx->show();
	//delete tx;
	//��ӡ������ڵڼ��С�
	TextQuery *tx = new TextQuery("e:/sgyt.txt");
	vector<int> vc = tx->query("ws");
	for (auto k : vc) {
		cout << k << endl;
	}
	delete tx;
}

//��������ϵ�д�ģ����ڴ����˺ܺõĹ���
class QueryResult1;

class TextQuery1 {
public:
	using line_no = vector<string>::size_type;
	TextQuery1(ifstream&);
	QueryResult1 query(string&) const;
private:
	shared_ptr<vector<string>> file;//����������ļ�
	map<string, shared_ptr<set<line_no>>> wm;//ÿ�����ʺ����кŵļ���
};

TextQuery1::TextQuery1(ifstream &is) : file(new vector<string>) {
	string text;
	while (getline(is, text))
	{
		file->push_back(text);//b�����ļ���ÿһ��
		int n = file->size() - 1;//��������ı�
		istringstream line(text);
		string word;
		while (line >> word) //������ÿ������
		{
			auto &lines = wm[word];//lines��һ��shared_ptr
			if (!lines) //�ж��Ƿ�Ϊ��ָ��
			{
				lines.reset(new set<line_no>);//����һ���µ�set
			}
			lines->insert(n);//�����кŲ���set��
		}
	}
}*/

/*int main()
{
	runQueryies();
	return 0;
}*/
