#pragma once
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<map>
#include<vector>
#include<set>
using namespace std;
//����query�����Ľ��
/*
class QueryResult 
{
public:
	using line_no = vector<string>::size_type;
	QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f) :sought(s), lines(p), file(f) {};
	set<line_no>::iterator begin() 
	{
		return lines->begin();
	}
	set<line_no>::iterator end() {
		return lines->end();
	}
	shared_ptr<vector<string>> get_file() {
		return file;
	}
private:
	string sought;//��ѯ����
	shared_ptr<set<line_no>> lines;//���ֵ��к�
	shared_ptr<vector<string>> file;//�����ļ�
};

//���������ļ�����������ͼ������query����������stringʵ�Σ�����QueryResult����
class TextQuery 
{
public:
	using line_no = vector<string>::size_type;
	TextQuery(string &);
	QueryResult query(const string &) const;
private:
	shared_ptr<vector<string>> file;//�����ļ�
	map<string, shared_ptr<set<line_no>>> wm;//ÿ�����ʵ������ڵ��кŵļ��ϵ�ӳ��
};

TextQuery::TextQuery(string &filePath) 
{
	ifstream read(filePath, ios::app);
	if (read.fail()) {
		cout << "�ļ���ȡʧ��" << endl;
		exit(0);
	}
	string word,line;
	while (getline(read, line))
	{
		file->push_back(line);
		int n = file->size();//��ǰ������
		istringstream is(line);
		while (is >> word) 
		{
			auto &lines = wm[word];
			if (lines) //������string û�г��ֹ�
			{
				lines.reset(new set<line_no>);//����һ���µĿռ�
			}
			lines->insert(n);
		}
	}
}
//��ѯ��������
QueryResult TextQuery::query(const string &s) const
{
	auto  res =wm.find(s);
	shared_ptr<set<line_no>> p(new set<line_no>);
	if (res == wm.end()) 
	{
		//˵����������
		 return QueryResult(s, p, file);
	}
	else 
	{
		return QueryResult(s, res->second, file);
	}
}


class Query;
//��ѯ��ĳ������
class Query_base
{
	friend class Query;
public:
	using line_no = vector<string>::size_type;
	virtual ~Query_base() = default;
private:
	//eval�����뵱ǰqueryƥ���QueryResult
	virtual QueryResult eval(const TextQuery&) const = 0;
	//rep�Ǳ�ʾ��ѯ��һ��string
	virtual string rep() const = 0;
};

//��ѯһ�������ĵ���
class WordQuery : public Query_base
{
	friend class Query;
	WordQuery(const string& s) :query_word(s) {};
	//������ࣺWordQuery���������м̳ж����Ĵ��麯��
	QueryResult eval(const TextQuery & t) const { return t.query(query_word); };
	string rep() const { return query_word; };
	string query_word;//Ҫ��ѯ�ĵ���
};

//��һ������ָ࣬��Query_base������Ķ���
class Query {
	//��������ʽ���shared_ptr�Ĺ��캯����������ʽ˽�е�
	friend Query operator ~ (const Query &);
	friend Query operator | (const Query &, const Query &);
	friend Query operator & (const Query&, const Query&);
public:
	Query(const string&); //����һ���µ�wordQuery
	//�ӿں��������ö�Ӧ��Query_base����
	QueryResult eval(const TextQuery &t) const 
	{
		return q->eval(t);
	}
	string rep() const { return q->rep(); }
private:
	Query(shared_ptr<Query_base> query) :q(query) { };
	shared_ptr<Query_base> q;
};
inline Query::Query(const string& s){
	Query_base *n = new WordQuery(s);
	q = make_shared<Query_base>(n);
};



//��ѯ����û�г��ֵ��еļ���
class NotQuery : public Query_base 
{
	friend Query operator ~ (const Query &);
	NotQuery(const Query& s) :query(s) {};
	QueryResult eval(const TextQuery & t) const;
	string rep() const { return "~("+query.rep()+")"; };
	Query query;
};
inline Query operator ~(const Query &op) 
{
	return shared_ptr<Query_base>(new NotQuery(op));
}

//��ѯ�����������Ĳ�ѯ
class BinaryQuery :public Query_base 
{
protected:
	BinaryQuery(const Query& a, const Query& b, string s) :lhs(a), rhs(b), opSym(s) {};
	string rep() const { return "{" + lhs.rep() + opSym + rhs.rep() + "}"; };
	Query lhs, rhs;//�����Ҳ���������
	string opSym;//�����������
};

//�ŷ������������������еĲ���
class OrQuery : public BinaryQuery 
{
	friend Query operator | (const Query &, const Query &);
	OrQuery(const Query& a, const Query& b) :BinaryQuery(a, b, "|") {};
	QueryResult eval(const TextQuery & t) const;
};
inline  Query operator | (const Query &a, const Query &b) 
{
	return shared_ptr<Query_base>(new OrQuery(a,b));
}

//�������������������еĽ���
class AndQuery : public BinaryQuery
{
	friend Query operator & (const Query &, const Query &);
	AndQuery(const Query&a,const Query& b):BinaryQuery(a, b, "&") {};
	QueryResult eval(const TextQuery & t) const;
};
inline  Query operator & (const Query &a, const Query &b)
{
	return shared_ptr<Query_base>(new AndQuery(a, b));
}
*/

/*
		eval ����������

*/

/*
QueryResult AndQuery::eval(const TextQuery & t) const
{
	auto right = rhs.eval(t);
	auto left = rhs.eval(t);
	auto left_line = make_shared<set<line_no>>(left.begin(), left.end());
	auto right_line = make_shared<set<line_no>>(right.begin(), right.end());
	shared_ptr<set<line_no>> setall;
	
	//����һ  find
	for (auto iter = left_line->begin(); iter != left_line->end(); iter++) 
	{
		if (right_line->find(*iter) != right_line->end()) {
			setall->insert(*iter);
		}
	}
	return  QueryResult(rep(), setall, left.get_file());
}
QueryResult OrQuery::eval(const TextQuery & t) const 
{
	auto right = rhs.eval(t);
	auto left = rhs.eval(t);
	auto ret_line = make_shared<set<line_no>>(left.begin(), left.end());
	ret_line->insert(right.begin(), right.end());
	return QueryResult(rep(), ret_line, left.get_file());

}
QueryResult  NotQuery::eval(const TextQuery & t) const 
{
	auto res = query.eval(t);
	auto s = res.get_file()->size();
	auto beg = res.begin();
	auto end = res.end();
	auto all = make_shared<set<line_no>>();
	for (size_t n = 0; n != s; n++)
	{
		if (beg == end || *beg != n)
		{
			all->insert(n);
		}
		else if(beg != end)
		{
			beg++;
		}

	}
	return QueryResult(rep(), all, res.get_file());
}
*/