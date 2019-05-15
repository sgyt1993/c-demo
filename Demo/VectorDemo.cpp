#include<iostream>
#include<vector>
#include<string>
using namespace std;
using std::string;
/*int main()
{
	string s("some string");
	if (s.begin() != s.end()) {
		auto it = s.begin();
		*it = toupper(*it);
		cout << *it << endl;
	}
}*/
/*int main()
{
	string s("some string");
	for (auto it = s.begin(); it != s.end() &&  !isspace(*it); it++) {
		*it = toupper(*it);
	};
	cout << s[1] << endl;
	return 0;
}*/
/*int main()
{
	string text = "s is mee";
	auto beg = text.begin(), end = text.end();
	auto mid = text.begin() + (end - beg) / 2;//初始化状态下的中间点
	while (mid != end && *mid != sought) {
		if (sought < *mid) {
			end = mid;
		}
		else {
			beg = mid + 1;
		}
		mid = beg + (end - beg) / 2;
	}

}*/

/*int main()
{
	int arr[10];
	int *parr[42];
	int a1[] = { 1,2,3 };
	int a3[5] = {1,2,3};//等价于a3[] = {1,2,3,0,0}
	string a4[3] = { "hi","bye" };//等价于a4[] = {"hi","bye",""}
	char a5[] = "aaaaaaa";
	cout << a5[2] << endl;
	return 0;
}*/

/*int main()
{
	string nums[] = { "one","two","three" };
	string *p = &nums[2];
	cout << *p << endl;//three
	string *p2 = nums;//等价于p2 = &nums[0]
	cout << *p2 << endl;//one
	return 0;
}*/

/*int main()
{
	int ia[] = { 0,1,23,3,4,5 };
	auto ia2(ia);//ia2是一个整形的指针，指向ia[0]
	cout << *ia2 << endl;
}*/

/*int main()
{
	int arr[] = { 1,2,3,4,5 };
	int *p = &arr[0];
	++p;//p指向arr[1]
	cout << *p << endl;//2
	return 0;
}*/

/*int main()
{
	int ia[] = { 0,1,2,3,4,5,6 };
	int *beg = begin(ia);//指向ia的首元素的指针
	cout << *beg << endl;//0
	int *last = end(ia);//指向ia尾元素的下一位置的指针；
	last--;
	cout << *last << endl;//6
	return 0;
}*/

/*int main()
{
	int ia[] = { 0,2,4,6,8 };
	int *p = &ia[2];
	int j = p[1];//p[1]等价于*（p+1），就等于ia[3]的元素
	int k = p[-2];//p[-2]等价于*（p-2）,就等于ia[0]的元素
	return 0;
}*/

/*int main()
{
	char ca[] = { 'c','+','+' };
	cout << strlen(ca) << endl;
}*/

/*int main()
{
	int ia[3][4] = {
		{0,1,2,3},
		{4,5,6,7},
		{8,9,10,11}
	};
	int ia1[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };//这个初始化和ia一样的效果
	int ic[3][4] = { { 0 },{ 4 },{ 8 } };//显示的初始化每行的首个元素
	int ic1[3][4] = { 0,3,6,9 };//显示的初始化第1行，其他元素执行初始化
	return 0;
}*/

/*int main()
{
	int ia[3][4] = {
		{0,1,2,3},
		{4,5,6,7},
		{8,9,10,11}
	};
	for (const auto &row : ia) {
		for (auto co1 : row) {
			cout << co1 << endl;
		}
	}

	return 0;

}*/

/*int main()
{
	
	return 0;
}*/

/*#include<set>
#include<map>
int main()
{
	//set<string> se{ "a","c","v","wdaw","awd","www" };
	map<string, string> mp{ {"s","a"} ,{"b","c"} };
	
	cout << mp["s"] << endl;
	return 0;
}*/


