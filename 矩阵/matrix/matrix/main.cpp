#include "matrix.h"
#include <vector>
#include <iostream>
using namespace std;


int main()
{	
	int a1[2] = { 1,2 };
	int a2[2] = { 3,4 };
	vector<int> v1(a1, a1 + 2);
	vector<int> v2(a2, a2 + 2);
	vector<vector<int>> v3;
	v3.push_back(v1);
	v3.push_back(v2);
	
	matrix<int> M(v3);

	std::cout <<M[0][0] << "	" << M[1][1] << std::endl;

	return 0;
}