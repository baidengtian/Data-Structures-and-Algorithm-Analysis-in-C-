/*
 * @Author: your name
 * @Date: 2020-03-31 15:51:01
 * @LastEditTime: 2020-03-31 16:32:39
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \move\Src\main.cpp
 */
// #include <iostream>
// #include <vector>

// using namespace std;

// void process(int& i)//左值引用
// {
//     cout << "process(int&): " << i << endl;
// }
// void process(int&& i)//右值引用
// {
//     cout << "process(int&&): " << i << endl;
// }
// void forward(int&& i)//中间函数
// {
//     cout << "forward(int&&): " << i << ",  ";
//     process(i);
// 	// process(std::forward<int>(i));
// }

// int main( ) {
 
//     int a = 0;
    
//     process(a);
    
//     process(1);
    
//     forward(1); //不完美的转交 右值传递后 却调用左值 原因转交过程中转变成一个named obj
    
//     forward(move(a));//强制转换为右值 也不好用 std::move()强制转换为右值引用
    
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <cstring>

// using namespace std;

// class Person
// {
    
// private:
//     int _age;
//     char* _name;
//     size_t _len;
//     void _test_name(const char *s)
//     {
//         _name = new char[_len+1];
//         memcpy(_name, s, _len);
//         _name[_len] = '\0';
//     }
    
// public:
//     //default ctor
//     Person(): _age(0) , _name(NULL), _len(0){cout<<"default constructor cotr"<< endl;}
    
//     Person(const int age, const char * p) : _age(age), _len(strlen(p)) {
//         _test_name(p);
//         cout<<"cotr"<<endl;
//     }
    
//     //dctor
//     ~Person(){
//         if(_name){
//             delete _name;
//         }
//         cout<<"default destructor dctor"<<endl;
//     }
    
//     // copy ctor
//     Person (const Person& p):_age(p._age),_len(p._len){
//         _test_name(p._name);
//         cout<<"copy ctor"<<endl;}
    
//     //copy assignment
//     Person & operator=(const Person& p)
//     {
//         if (this != &p){
//             if(_name) delete _name;
//             _len = p._len;
//             _age = p._age;
//             _test_name(p._name);
//         }
//         else{
//             cout<< "self Assignment. Nothing to do." <<endl;
//         }
//         cout<<"copy assignment"<<endl;
//         return *this;
//     }
// };

// int main(int argc, const char * argv[]) {
    
//     Person * obj = new Person();
    
//     vector<Person> v1;
    
//     v1.push_back(*obj);

//     delete obj;
//     return 0;
// }


#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Person
{
    
private:
    int _age;
    char* _name;
    size_t _len;
    void _test_name(const char *s)
    {
        _name = new char[_len+1];
        memcpy(_name, s, _len);
        _name[_len] = '\0';
    }
    
public:
    //default ctor
    Person(): _age(0) , _name(NULL), _len(0){cout<<"default cotr"<< endl;}
    
    Person(const int age, const char * p) : _age(age), _len(strlen(p)) {
        _test_name(p);
        cout<<"cotr"<<endl;
    }
    
    //dctor
    ~Person(){
        if(_name){
            delete _name;
        }
        cout<<"default dctor"<<endl;
    }
    
    // copy ctor
    Person (const Person& p):_age(p._age),_len(p._len){
        _test_name(p._name);
        cout<<"copy ctor"<<endl;}
    
    //copy assignment
    Person & operator=(const Person& p)
    {
        if (this != &p){
            if(_name) delete _name;
            _len = p._len;
            _age = p._age;
            _test_name(p._name);
        }
        else{
            cout<< "self Assignment. Nothing to do." <<endl;
        }
        cout<<"copy assignment"<<endl;
        return *this;
    }
    
    // move cotr , wihth "noexcept"
    Person(Person&& p) noexcept :_age(p._age) , _name(p._name), _len(p._len){
        cout<<"move ctor"<<endl;
        p._age = 0;
		//必须为NULL 如果你把这里设为空 
		//那么这个函数走完之后将调用析够函数 因为当前的Person类 
		//和你将要析够的Person的_name指向同一部分 析构部分见析构函数
        p._name = NULL;
    }
    // move assignment
    Person& operator=(Person&& p) noexcept {
        
        if (this != &p)
        {
            if(_name) delete _name;
            _age  = p._age;
            _len  = p._len;
            _name = p._name;
            p._age  = 0;
            p._len  = 0;
            p._name = NULL;
        }
        cout<<"move assignment"<<endl;
        return *this;
    }
};

int main(int argc, const char * argv[]) {
    
    Person * obj = new Person();
    
    vector<Person> v1;

    v1.push_back(move(*obj));

    delete obj;
    return 0;
}