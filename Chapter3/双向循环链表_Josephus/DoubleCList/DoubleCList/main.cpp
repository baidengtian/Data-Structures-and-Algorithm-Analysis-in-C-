#include "DoubleCList.h"
#include <iostream>
using namespace std;

int main()
{

	doubleCList<int> l1;
	l1.PushBack(1);
	l1.PushBack(2);
	l1.PushBack(3);
	l1.PushBack(4);
	l1.PushBack(5);
	l1.print();
	std::cout << l1;
	l1.josephus();
	// for(auto it = l1.begin(); it != l1.end();++it)
// 	auto it = l1.begin();
// 	while(it != l1.end())
// 	{
// 		it++;
// 		std::cout << std::endl << *it << std::endl;
// 
// 	}
	
//	l1.josephus();
//  	l1.Erase(l1.Find(2));
//  	l1.print();
// 	l1.Erase(l1.Find(3));
// 	l1.print();
// 	l1.Erase(l1.Find(1));
// 	l1.print();
// 	// cout << l1;
// 	bool m_flag = l1.Empty();
// 	int m_size = l1.size();
	return 0;
}