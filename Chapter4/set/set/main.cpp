#include "main.h"
#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <string.h>
#if defined(_MSC_VER)
#define strcasecmp _stricmp
#endif
class CaseInsensitiveCompare
{
public:
	bool operator()( const std::string & lhs, const std::string & rhs)	const
	{
		// 比较时忽略字符换中的大小写
		return strcasecmp(lhs.c_str(), rhs.c_str()) < 0;
	}
};
int main()
{
	std::set< std::string,CaseInsensitiveCompare > s;
	s.insert( "hello" );
	s.insert( "HELLO" );
	std::cout << "The size is : " << s.size() << std::endl;

	return 0;
}

