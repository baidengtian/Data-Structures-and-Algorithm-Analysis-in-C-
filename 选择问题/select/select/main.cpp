#include "select.h"
#include <vector>

int main()
{
	int ia[10] = {9,0,1,4,2,3,6,5,7,8};
	std::vector<int> vi(ia,ia+10);
	select s(vi);
	std::vector<int> vi2 = s.GetKMax(2);


	return 0;
}