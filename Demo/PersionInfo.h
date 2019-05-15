#pragma once
#include<iostream>
#include<string>
#include<vector>
using std::string;
using namespace std;
using std::vector;
struct PersonInfo
{
	string name;
	vector<string> phones;
public:
	PersonInfo po(string str, vector<string> vc) 
	{
			name = str;
			phones = vc;
	}
	PersonInfo () = default;
};
