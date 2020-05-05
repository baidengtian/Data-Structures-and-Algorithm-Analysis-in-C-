#ifndef __EMPLOY_H
#define __EMPLOY_H
#include "Hash_Tab.h"
#include <string>

class Employ
{
private:
    std::string name;
    double salary;
    int seniority;
public:
    Employ(std::string theName, double theSalary = 0, int theSeniority = 0 ) 
    : name( theName ), salary( theSalary ), seniority( theSeniority )  
    {

    }
    ~Employ()
    {

    }
    const std::string & getName( )  const
    {
        return this->name;
    }
    bool operator == ( const Employ & rhs ) const
    {
        return getName( ) == rhs.getName( );
    }
    bool operator != ( const Employ & rhs ) const
    {
        return !( *this == rhs );
    }
};



class  Hash_Employ
{
public:
    size_t operator( )( const Employ & item )
	{
		size_t hashVal = 0;
        std::string k = item.getName();
		for( char ch : k )
			hashVal = 37 * hashVal + ch;
		return hashVal;
	}
};










#endif