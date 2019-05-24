#pragma once
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<map>
#include<vector>
#include<set>
using namespace std;
//保存query操作的结果
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
	string sought;//查询单词
	shared_ptr<set<line_no>> lines;//出现的行号
	shared_ptr<vector<string>> file;//输入文件
};

//给定读入文件，建构查找图，包含query操作，接受string实参，返回QueryResult对象
class TextQuery 
{
public:
	using line_no = vector<string>::size_type;
	TextQuery(string &);
	QueryResult query(const string &) const;
private:
	shared_ptr<vector<string>> file;//输入文件
	map<string, shared_ptr<set<line_no>>> wm;//每个单词到它所在的行号的集合的映射
};

TextQuery::TextQuery(string &filePath) 
{
	ifstream read(filePath, ios::app);
	if (read.fail()) {
		cout << "文件读取失败" << endl;
		exit(0);
	}
	string word,line;
	while (getline(read, line))
	{
		file->push_back(line);
		int n = file->size();//当前的行数
		istringstream is(line);
		while (is >> word) 
		{
			auto &lines = wm[word];
			if (lines) //如果这个string 没有出现过
			{
				lines.reset(new set<line_no>);//分配一个新的空间
			}
			lines->insert(n);
		}
	}
}
//查询出这个结果
QueryResult TextQuery::query(const string &s) const
{
	auto  res =wm.find(s);
	shared_ptr<set<line_no>> p(new set<line_no>);
	if (res == wm.end()) 
	{
		//说明不在文中
		 return QueryResult(s, p, file);
	}
	else 
	{
		return QueryResult(s, res->second, file);
	}
}


class Query;
//查询类的抽象基类
class Query_base
{
	friend class Query;
public:
	using line_no = vector<string>::size_type;
	virtual ~Query_base() = default;
private:
	//eval返回与当前query匹配的QueryResult
	virtual QueryResult eval(const TextQuery&) const = 0;
	//rep是表示查询的一个string
	virtual string rep() const = 0;
};

//查询一个给定的单词
class WordQuery : public Query_base
{
	friend class Query;
	WordQuery(const string& s) :query_word(s) {};
	//具体的类：WordQuery将定于所有继承而来的纯虚函数
	QueryResult eval(const TextQuery & t) const { return t.query(query_word); };
	string rep() const { return query_word; };
	string query_word;//要查询的单词
};

//是一个借口类，指向Query_base派生类的对象
class Query {
	//运算符访问接受shared_ptr的构造函数，而函数式私有的
	friend Query operator ~ (const Query &);
	friend Query operator | (const Query &, const Query &);
	friend Query operator & (const Query&, const Query&);
public:
	Query(const string&); //建构一个新的wordQuery
	//接口函数：调用对应的Query_base操作
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



//查询对象没有出现的行的集合
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

//查询两个运算对象的查询
class BinaryQuery :public Query_base 
{
protected:
	BinaryQuery(const Query& a, const Query& b, string s) :lhs(a), rhs(b), opSym(s) {};
	string rep() const { return "{" + lhs.rep() + opSym + rhs.rep() + "}"; };
	Query lhs, rhs;//左侧和右侧的运算对象
	string opSym;//运算符的名字
};

//才返回两个运算对象出现行的并集
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

//返回两个运算对象出现行的交集
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
		eval 方法的重载

*/

/*
QueryResult AndQuery::eval(const TextQuery & t) const
{
	auto right = rhs.eval(t);
	auto left = rhs.eval(t);
	auto left_line = make_shared<set<line_no>>(left.begin(), left.end());
	auto right_line = make_shared<set<line_no>>(right.begin(), right.end());
	shared_ptr<set<line_no>> setall;
	
	//方法一  find
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