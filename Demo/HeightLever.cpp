#include<iostream>
#include<string>
#include<tuple>
#include<vector>
#include<list>
using namespace std;
//tuple����
/*+int main()
{
	//tuple���ٶ���������ݽṹ
	tuple<size_t, size_t, size_t> three1 = { 1,2,3 };
	tuple<size_t, size_t, size_t> three{1,2,3};
	tuple<string, vector<double>, int, list<int>> someVal("constants", { 2.31,12.31 }, 2, { 12,12,3 });

	//ʹ��make_tuple
	//auto item = make_tuple("wdwd", 123, 12, 12.3, {1,2,1});//ò�Ʋ��ܷ�����
	auto item= make_tuple("wdwd", 123, 12, 12.3);

	//����tuple�ĳ�Ա
	auto first = get<0>(three1);
	cout << first << endl;//1
	get<0>(three1) = 2;
	cout << get<0>(three1) << endl;//2
	auto listd = get<1>(someVal);
	cout << listd[0] << endl;// 2.31
	return 0;
}*/

//����������ѯtuple�ĳ�Ա����������
/*int main() 
{
	tuple<int, vector<string>, double> t1 = { 12,{"wdw","dd","three"},3.15 };
	typedef decltype(t1) trans;//trans��item������
	//����trans���Ͷ����г�Ա������
	size_t st = tuple_size<trans>::value;
	cout << st << endl;//3;
	//ȡ��t1Ԫ�صĵ�0��Ԫ�ص�����
	tuple_element<0, decltype(t1)>::type cnt = 2;
	cout << get<0>(t1) << endl;//12û�иı�t1
	return 0;
}*/


/*int main()
{
	tuple<string, string> p1("1","2");
	tuple<size_t, size_t> p2(1, 2);
	//bool p = p1 < p2;���󣬲�ͬ���Ͳ��ܱȽ�
	tuple<size_t, size_t, size_t> p3(1, 2, 3);
	//bool p = p2 > p3;��Ա������ͬ
	tuple<size_t, size_t> p4(0, 4);
	tuple<size_t, size_t> p5(3, 4);
	cout << (p4 > p2) << endl;//0
	cout << (p5> p2) << endl;//1 Ҫȫ������ǰ���еĲ���������true
	return 0;
}*/
/*#include <algorithm>
class Sales_data {

};
//matches��������Ա��һ����������������ָ�����vector��Ԫ�ص�vector
typedef tuple<
	vector<Sales_data>::size_type,
	vector<Sales_data>::const_iterator,
	vector<Sales_data>::const_iterator
> matches;
//fils����ÿ���������ۼ�¼,
//findBook����һ��vector��ÿ�������˸����鼮����������ж���һ��
vector<matches> findBook(const vector<vector<Sales_data>> &files, const string &book)
{
	vector<matches> ret;
	for (auto iter = files.cbegin(); iter != files.cend(); iter++) 
	{
		//������ͬISBN��Sales_data��Χ
		auto found = equal_range(iter->cbegin(), iter->cend(), book, [](string f, string b) {return f == b; });
		if (found.first != found.second)
			ret.push_back(make_tuple(iter - files.cbegin(), found.first, found.second));
	}
	return ret;//�ҵ�������ƥ��Ľ��
}*/

//ʹ��tuple���ض��ֵ
/*int main()
{
	vector<int> k = { 12,1,3,1,23,1,3,12,543,42,34,23,42,33,2 };
	cout << *k.cbegin() << endl;//12
	vector<int>::size_type size = (k.begin() + 5) - k.begin();//���ַ�ʽ����������е�ǰ�ĳ���
	cout << size << endl;
	return 0;
}*/
#include<bitset>
//bitset����
/*int main() 
{
	bitset<32> b1("1010");
	return 0;
}*/

#include<regex>
/*int main()
{
	string pattern{ "\\d{3}-\\d{8}|\\d{4}-\\d{7}" };//�绰����
	regex rs(pattern);
	string tel = "0319-9876543";
	bool k = regex_match(tel, rs);
	cout << k << endl;
	return 0;
}*/


/*int main()
{
	regex r("abcd", regex::icase);
	string str = "ABCd";
	bool flag = regex_match(str, r);
	cout << flag << endl;
	return 0;
}*/


/*int main()
{
	regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);
	cmatch results;//ƥ����string ���
	if (regex_search("myfile.cc", results, r))//����char
		cout << results.str() << endl;

	smatch results1;
	string vc{ "myfile.cc" };
	if (regex_search(vc, results1, r))//������string
		cout << results1.str() << endl;
	return 0;
}*/


//ƥ����regex����������sregex_iterator
/*int main()
{
	//����һ���ַ�����c���ַ���ei
	string pattern("[^c]ei");
	//��������pattern�����е���
	pattern = "[[:alnum:]]*" + pattern + "[[:alnum:]]*";
	regex r(pattern, regex::icase);
	string file = "receipt freind theif receive";
	for (sregex_iterator it(file.begin(), file.end(), r), end_it; it != end_it; ++it)
	{
		auto pos = it->prefix().str();//ǰ��һ������
		auto fix = it->suffix().str();//�������е���
		cout << pos << endl;
		cout << it->str() << endl;
		cout << fix << endl;
	}
	//friend 
	//theif
	return 0;
}*/

/*int main() 
{
	regex r("([[:alnum:]]+)\\.(cpp|cxx|cc)$", regex::icase);//myfile.cc��myfile��cc
	regex r1("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);//myfile.cc��cc
	regex r2("[[:alnum:]]+\\.cpp|cxx|cc$", regex::icase);//cc
	string vc{ "myfile.cc" };
	smatch results;//ƥ����string ���
	for (sregex_iterator it(vc.begin(), vc.end(), r2), it_end; it != it_end; it++) 
	{
		int i = 0;
		auto k = *it;
		for (auto cit = k.begin(); cit != k.end(); cit++) 
		{
			cout << cit->str() << endl;//��������
		}
	}
	return 0;
}*/


//regex_replace
 
/*int main()
{
	//�ʺ�(?)��ʾ֮ǰ�Ŀ���ѡ��
	std::string phone =
		"(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
	regex r(phone);
	//����
	string fmt("$2.$5.$7");
	string number("(908)555-1800");
	bool k = regex_match(number, r);
	cout << k << endl;
	cout << regex_replace(number, r, fmt) << std::endl;

	string file("Caroline (201)555-2368 862-55-0123");
	cout << regex_replace(file, r, fmt) << std::endl;
	cout << regex_replace(file, r, fmt,regex_constants::format_no_copy) <<endl;
}*/

/*int main() 
{
	string str = "1994 is my birth year";
	regex r("\\d{4}");
	string fmt = "19";
	string replace1 = regex_replace(str, r, fmt);//�õ����򵽵����ݽ����޸�
	cout << replace1 << endl;//19 is my birth year
	string replace2 = regex_replace(str, r, fmt,regex_constants::format_no_copy);//����ʾ��ƥ���ֵ
	cout << replace2 << endl;//19
	return 0;
}*/

/*int main() 
{
	string phone = "(\\()?(\\d{3})(\\))?(\\d{3})([-.])?(\\d{4})";
	regex r(phone);
	smatch m;
	string s = "(201)555-2368 862-555-123";
	string fmt = "$2.$5.$7";
	cout<<regex_replace(s, r, fmt)<<endl;
	return 0;
}*/
#include<random>
#include<set>
//�����
/*int main() 
{
	default_random_engine e;
	set<unsigned> s;
	for (int i = 0; s.size()< 30; i++) 
	{
		s.insert(e());
	}
	for (auto iter = s.begin(); iter != s.end(); iter++) 
	{
		cout << *iter << endl;
	}
	return 0;
}*/

/*int main() 
{
	uniform_int_distribution<int> u(0, 255);
	default_random_engine e;
	set<int> k; 
	for (int i = 0; k.size() < 20; i++) 
	{
		k.insert(u(e));
	}
	for (auto iter = k.begin(); iter != k.end(); iter++)
	{
		cout << *iter << endl;
	}
	return 0;
}*/

//���������
/*int main()
{
	default_random_engine u1(200001);
	default_random_engine u2;
	u2.seed(200001);
	default_random_engine u3;
	//u1��u2��ͬ�����ӣ���ô���ɵ��������ͬ
	for (int i = 0; i < 20; i++)
	{
		cout << u1() << endl;
	}
	cout << "........................" << endl;
	for (int i = 0; i < 20; i++)
	{
		cout << u2() << endl;
	}
	return 0;
}*/


//����������ֲ�(����С�������)
/*int main()
{
	default_random_engine e;
	uniform_real_distribution<double> u(0, 1);
	for (int i = 0; i < 20; i++) {
		cout<<u(e)<<endl;
	}
}*/

//���������boolֵ
/*int main() 
{
	default_random_engine e;
	bernoulli_distribution b;//Ĭ��50%�Ļ���
	for (int i = 0; i < 20; i++) {
		bool flag = b(e);
		cout << flag << endl;
	}
}*/

#include<fstream>
#include<sstream>
#include<string>
//���boolֵʱ��Ĭ����1,0�����true,false
/*int main() 
{
	ofstream f("e:/sgyt.txt",ios::out);
	if (f.fail()) 
	{
		cout << "��ʧ��" << endl;
	}
	f << "default bool values:" << true << "   " << false ;//default bool values:1   0
	f << "\nalphe bool values:" << boolalpha << true << "    " << false ;//alphe bool values:true    false
	f.close();
	return 0;
}*/

//�������
/*int main() 
{

	ofstream f("e:/sgyt.txt", ios::out);
	if (f.fail())
	{
		cout << "��ʧ��" << endl;
	}
	f << showbase;//��ӡ����ʱ��ʾ����
	f << "default:" << 20 << "   " << 1024 <<endl;
	f << "octal:" << oct << 20 << "   " << 1024 << endl;
	f<<"hex:"<<hex<< 20 << "   " << 1024 << endl;
	f<<"decimal:"<<dec << 20 << "   " << 1024 << endl;
	f.close();
	return 0;
}*/
/*
default:20   1024
octal:24   2000
hex : 14   400
decimal : 20   1024*/


//ָ����ӡ����
//ͨ������io����precision��Ա��ʹ��setprecision���ݷ����ı侫��
#include<iomanip>
/*int main() 
{
	ofstream f("e:/sgyt.txt", ios::out);
	if (f.fail())
	{
		cout << "��ʧ��" << endl;
	}
	//cout.precision���ص�ǰ����ֵ
	f << "Precision:" << f.precision() << ",Value:" << sqrt(2.0) << endl;
	//cout.precision(12)����ӡ��������Ϊ12λ����
	f.precision(12);
	f << "Precision" << f.precision() << ",Value:" << sqrt(2.0) << endl;
	//ʹ��setprecision���ݷ�
	f<<setprecision(3);
	f << "Precision" << f.precision() << ",Value:" << sqrt(2.0) << endl;
	f.close();
	return 0;
}*/
/*
Precision:6,Value:1.41421
Precision12,Value:1.41421356237
Precision3,Value:1.41
*/


/*int  main() 
{
	ofstream f("e:/sgyt.txt", ios::out);
	if (f.fail())
	{
		cout << "��ʧ��" << endl;
	}
	f << 10.0 << endl;
	f << showpoint << 10.0 << noshowpoint << "    " << 10.0 << endl;
	//10
	//10.0000    10
	return 0;
}*/


//С���Ĳ�����
/*int main() 
{
	ofstream f("e:/sgyt.txt", ios::out);
	if (f.fail())
	{
		cout << "��ʧ��" << endl;
	}
	int i = -16;
	double d = 3.14159;
	//���׵�һ�У�ʹ���������С12��λ��
	f << "i:" << setw(12) << i << "next col" << "\n"
		<< "d:" << setw(12) << d << "next col" << "\n";
	//���׵�һ�У������������
	f << left
		<< "i:" << setw(12) << i << "next col" << "\n"
		<< "d:" << setw(12) << d << "next col" << "\n"
		<< right;//�ָ���������
	//���׵�һ�У��Ҷ���������
	f << right
		<< "i:" << setw(12) << i << "next col" << "\n"
		<< "d:" << setw(12) << d << "next col" << "\n";
	//���׵�һ�У�����������ڲ�
	f <<internal
		<< "i:" << setw(12) << i << "next col" << "\n"
		<< "d:" << setw(12) << d << "next col" << "\n";
	//���׵�һ�У���#��Ϊ�����ַ�
	f << setfill('#')
		<< "i:" << setw(12) << i << "next col" << "\n"
		<< "d:" << setw(12) << d << "next col" << "\n"
		<< setfill(' ');
	
	i:         -16next col
d:     3.14159next col
i:-16         next col
d:3.14159     next col
i:         -16next col
d:     3.14159next col
i:-         16next col
d:     3.14159next col
i:-#########16next col
d:#####3.14159next col

	
	return 0;
}*/

//δ��ʽ�����/�������
//sell,tell֧���������
/*int main() 
{
	ifstream f("e:/sgyt.txt", ios::out);
	if (f.fail())
	{
		cout << "��ʧ��" << endl;
	}
	//��ǰ��λ��
	streampos pos = f.tellg();
	if (ios::beg == pos) 
	{
		cout << "the file is beginning" << endl;
	}
	return 0;
}*/

/*int main() 
{
	ifstream f("e:/sgyt.txt", ios::out);
	if (f.fail())
	{
		cout << "��ʧ��" << endl;
	}
	string line;
	getline(f, line);
	//�õ���ǰ��pos��
	streampos pos = f.tellg();
	f.close();
	//���¿�һ��������
	ifstream g("e:/sgyt.txt", ios::out);
	if (g.fail())
	{
		cout << "��ʧ��" << endl;
	}
	//��g��������ǵ��ղŶ�ȡ��λ��
	g.seekg(pos);
	getline(g, line);//����ȡ���ľ��Ǳ��ļ��ĵڶ����ļ�
	cout << line << endl;
	return 0;
}*/

//�����ƶ�ȡ�ļ��������
/*int  main() 
{
	ifstream read("e:/Explosion_4k.jpg", ios::binary);
	ofstream out("e:/tupian.jpg", ios::binary);
	if (out.fail()) 
	{
		string command;
		string path = "e:/tupian.jpg";
		command = "mkdir -p " + path;
		system(command.c_str());
	};
	int ch;//ʹ��һ��int,������char����get()�ķ���ֵ
	while ((ch = read.get()) != EOF) 
	{
		out.put(ch);
	}
	read.close();
	out.close();
	return 0;
}*/






