#ifndef __SELECT_H
#define __SELECT_H

#include <vector>
class select
{
public:
	select(std::vector<int> v):m_array(v)
	{

	}
	std::vector<int> GetKMax(int k)	const; 
private:
	std::vector<int> m_array;
};


#endif
