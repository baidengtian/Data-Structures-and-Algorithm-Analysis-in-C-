#ifndef __VECTOR_H
#define __VECTOR_H



#include <algorithm>


template <typename Object>
class Vector
{
public:
	explicit Vector(int initSize = 0) : theSize(initSize),			// ���캯��
		theCapacity(initSize + SPARE_CAPACITY)
	{
		objects = new Object[theCapacity];
	}
	Vector(const Vector& rhs) : theSize(rhs.theSize),				// �������캯��
		theCapacity(rhs.theCapacity),objects(nullptr)
	{
		objects = new Object[theCapacity];
		for(int k = 0; k < theSize; ++k)
			objects[k] = rhs.objects[k];
	}
	Vector& operator = (const Vector& rhs)							// ��д = 
	{
		Vector copy(rhs);
		std::swap(*this,copy);
		return *this;
	}
	~Vector()														// ��������
	{
		delete[] objects;
	}
	void resize(int newSize)										// ����Vector����ʹ�õĿռ��С
	{
		if(newSize > theCapacity)
			reseve(newSize * 2);
		theSize = newSize;
	}
	void reserve(int newCapacity)									// ����Vector����Ԥ���Ŀռ��С
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
	void push_back(const Object& x) // ĩβ��������
	{
		if(theSize == theCapacity)
			reserve(2 * theCapacity + 1);
		objects[theSize++] = x;
	}
	void pop_back()					// ����ĩβ����
	{
		--theSize;
	}
	const Object& back()	const	// �������һ������
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
	int theSize;													// Vector����ʹ�õĿռ��С
	int theCapacity;												// Vector����Ԥ���Ŀռ��С
	Object* objects;
};



#endif



