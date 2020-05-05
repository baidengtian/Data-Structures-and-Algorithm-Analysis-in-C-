#include "Vector.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	// std::vector<int> v3;
	
	Vector<int> v1(3);
	v1.push_back(1);
	v1.push_back(2);
	Vector<int> v2;
	v2 = v1;
	int a1 = v1.back();
	int a2 = v2.back();
	v2.pop_back();
	// v2[1] = 0;
	a1 = v1.back();
	a2 = v2.back();


	std::vector<std::string> vs1;
	vs1.push_back("bai");
	vs1.push_back("deng");
	vs1.push_back("tian");
	std::vector<std::string> vs2;
	vs2.push_back("aaa");
	vs2.push_back("bbb");
	vs2.push_back("ccc");
	std::swap(vs1,vs2);
	return 0;
}


