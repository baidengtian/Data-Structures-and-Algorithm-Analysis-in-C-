#include "singleList.h"
#include <iostream>

int main()
{
	singleList<int> sl1;
	sl1.push_back(1);
	sl1.push_back(2);
	sl1.push_back(3);
// 	auto it = sl1.begin();
// 	for(int i = 0; i < sl1.size(); i++)
// 		std::cout << *(++it) << std::endl;
	sl1.print();
	return 0;

}