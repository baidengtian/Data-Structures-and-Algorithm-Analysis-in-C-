#ifndef __VECTOR_H
#define __VECTOR_H



#include <algorithm>


template <typename Object>
class Vector
{
public:
	explicit Vector(int initSize = 0) : theSize(initSize),			// 构造函数
		theCapacity(initSize + SPARE_CAPACITY)
	{
		objects = new Object[theCapacity];
	}
	Vector(const Vector& rhs) : theSize(rhs.theSize),				// 拷贝构造函数
		theCapacity(rhs.theCapacity),objects(nullptr)
	{
		objects = new Object[theCapacity];
		for(int k = 0; k < theSize; ++k)
			objects[k] = rhs.objects[k];
	}
	Vector& operator = (const Vector& rhs)							// 重写 = 
	{
		Vector copy(rhs);
		std::swap(*this,copy);
		return *this;
	}
	~Vector()														// 析构函数
	{
		delete[] objects;
	}
	void resize(int newSize)										// 重置Vector容器使用的空间大小
	{
		if(newSize > theCapacity)
			reseve(newSize * 2);
		theSize = newSize;
	}
	void reserve(int newCapacity)									// 重置Vector容器预留的空间大小
	{
		if(newCapacity < theSize)
			return;
		Object* newArray = new Object[newCapacity];
		for(int k=0; k < theSize; ++k)
			newArray[k] = std::move(objects[k]);

		theCapacity = newCapacity;
		std::swap(objects,newArray);
		delete[] newArray;

	}
	Object& operator [] (int index)
	{
		if ( index > theSize || index < 0 )
			return -1;
		else
			return objects[index];
	}
	const Object& operator [] (int index)	const
	{
		if ( index > theSize || index < 0 )
			return -1;
		else
			return objects[index];
	}
	bool empty()	const
	{
		return size()==0;
	}
	int size()	const
	{
		return theSize;
	}
	int capacity()	const
	{
		return theCapacity;
	}
	void push_back(const Object& x) // 末尾插入数据
	{
		if(theSize == theCapacity)
			reserve(2 * theCapacity + 1);
		objects[theSize++] = x;
	}
	void pop_back()					// 弹出末尾数据
	{
		--theSize;
	}
	const Object& back()	const	// 返回最后一个数据
	{
		return objects[theSize - 1];
	}
	typedef Object* iterator;
	typedef const Object* const_iterator;

	iterator begin()
	{
		return &objects[0];
	}
	const_iterator begin()	const
	{
		return &objects[0]; 
	}
	iterator end()
	{
		return &objects[size()];
	}
	const_iterator end()	const
	{
		return &objects[size()];
	}
	static const int  SPARE_CAPACITY = 16;
private:
	int theSize;													// Vector容器使用的空间大小
	int theCapacity;												// Vector容器预留的空间大小
	Object* objects;
};



#endif



