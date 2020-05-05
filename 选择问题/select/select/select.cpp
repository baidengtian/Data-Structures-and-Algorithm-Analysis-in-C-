#include "select.h"
#include <vector>
#include <algorithm>
std::vector<int> select::GetKMax(int k)	const
{
	std::vector<int> vi;
	for(int i = 0; i < k; i++)
	{
		vi.push_back(m_array[i]);
	}
	// 从小到大排序
	std::sort(vi.begin(),vi.end());
	for (int i = k ; i < m_array.size(); i++)
	{
		if(vi[0] < m_array[i])
		{
			vi[0] = m_array[i];
			std::sort(vi.begin(),vi.end());
		}
	}
	return vi;
}