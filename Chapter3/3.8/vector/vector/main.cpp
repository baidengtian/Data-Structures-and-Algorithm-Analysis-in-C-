#include "Vector.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	
	Vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.insert(v1.begin(),100);
	v1.insert(v1.end(),200);
	v1.erase(v1.end());
	v1.erase(v1.begin());
	for(auto it = v1.begin(); it != v1.end(); it++)
		std::cout << *it << "  ";

	return 0;
}


