#include <iostream>
#include <functional>
#include <vector>

// 采用自己定义的函数对象
template <typename Object, typename Comparator>
const Object& findMax(const std::vector<Object>& arr, Comparator isLessThan)
{
	int maxIndex = 0;
	for (int i = 1; i < arr.size(); i++)
		if (isLessThan(arr[maxIndex], arr[i]))
			maxIndex = i;

	return arr[maxIndex];

}
// 采用STL标准库提供的less函数对象
template <typename Object>
const Object& findMax(const std::vector<Object>& arr)
{
	return findMax(arr, std::less<Object>{});
}
// 函数对象 相当于重载 ()
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


