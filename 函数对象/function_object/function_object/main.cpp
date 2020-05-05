#include <iostream>
#include <functional>
#include <vector>

// �����Լ�����ĺ�������
template <typename Object, typename Comparator>
const Object& findMax(const std::vector<Object>& arr, Comparator isLessThan)
{
	int maxIndex = 0;
	for (int i = 1; i < arr.size(); i++)
		if (isLessThan(arr[maxIndex], arr[i]))
			maxIndex = i;

	return arr[maxIndex];

}
// ����STL��׼���ṩ��less��������
template <typename Object>
const Object& findMax(const std::vector<Object>& arr)
{
	return findMax(arr, std::less<Object>{});
}
// �������� �൱������ ()
class CaseInsensitiveCompare
{
public:
	bool operator()(const std::string& lhs, const std::string& rhs)	const
	{
		return std::strcmp(lhs.c_str(), rhs.c_str()) < 0;
	}
};

int main()
{
	std::vector<std::string> arr = {"ZEBRA", "alligator", "crocodile"};

	std::cout << findMax(arr, CaseInsensitiveCompare{}) << std::endl;

	std::cout << findMax(arr) << std::endl;


	return 0;
}


