/* 
* Class: CS 3305 
* Term : Spring 2019
* Name : Leonard Hayes
* Instructor : Betty Kretlow
* Assignment : 3
*/


#include "set.h"
#include <cassert>
#include<iostream>

using namespace std;

//default constructor

set::set(size_type initial_capacity )
{

	set::capacity= 30;

	used = 0;

	data = new value_type[capacity];

}

set::set(const set& source)
{
	capacity = source.capacity;
	used = source.used;
	data = new value_type[capacity];
	for (int i = 0; i < used; i++)
		data[i] = source.data[i];
}

set::~set()
{
	used = 0;
	capacity = 0;
	delete[] data;
}

void set::insert(const value_type& entry)
{
	if (capacity <= used)
	{
		resize(capacity + 1);
	}
	bool exists = false;
	for (int i = 0; i < used; i++)
	{
		if (data[i] == entry)
		{
			exists = true;
			break;
		}
	}
	if (!exists && used < capacity)
	{
		data[used] = entry;
		used++;
	}
}

void set::remove(const value_type& entry)
{
	int position = -1;
	for (int i = 0; i < used; i++)
	{
		if (data[i] == entry)
		{
			position = i;
			break;
		}
	}
	if (position != -1)
	{
		for (int i = position; i < used - 1; i++)
			data[i] = data[i + 1];
		used--;
	}
}

set::size_type set::size() const 
{
	return used;
}

bool set::contains(const value_type& entry) const
{
	for (int i = 0; i < used; i++)
		if (data[i] == entry) 
			return true;
	return false;
}

set set_union(const set& s1, const set& s2)
{
	set temp;
	for (int i = 0; i < s1.size(); i++)
		temp.insert(s1.data[i]);
	for (int i = 0; i < s2.size(); i++)
		temp.insert(s2.data[i]);
	return temp;
}

set set_intersection(const set& s1, const set& s2)
{
	set temp;
	for (int i = 0; i < s1.size(); i++)
	{
		if (s2.contains(s1.data[i]))
			temp.insert(s1.data[i]);
	}
	return temp;
}

set set_difference(const set& s1, const set& s2)
{
	set temp;
	for (int i = 0; i < s1.size(); i++)
		if (!s2.contains(s1.data[i]))
			temp.insert(s1.data[i]);
	return temp;
}

bool is_subset(const set& s1, const set& s2)
{
	for (int i = 0; i < s1.size(); i++)
		if (!s2.contains(s1.data[i]))
			return false;
	return true;
}

bool operator == (const set& s1, const set& s2)
{
	if (is_subset(s1, s2) && is_subset(s2, s1))
		return true;
	return false;
}

std::ostream& operator << (std::ostream& output, const set& s)
{
	output << "( ";
	for (int i = 0; i < s.size() - 1; i++)
		output << s.data[i] << ", ";
	output << s.data[s.size() - 1] << " )";
	return output;
}

set& set::operator = (const set& source)
{
	set temp;
	temp.capacity = source.capacity;
	temp.used = source.used;
	temp.data = new value_type[capacity];
	for (int i = 0; i < used; i++)
		temp.data[i] = source.data[i];
	return temp;
}

set::size_type set::find(const value_type& entry) const
{
	size_type pos = 0;
	for (int i = 0; i < used; i++)
	{
		if (data[i] == entry)
		{
			pos = i;
			return i;
		}	
	}
	return -1;
}

void set::resize(unsigned int new_size)
{
	value_type* temp = new value_type[new_size];
	for (int i = 0; i < used; i++)
		temp[i] = data[i];
	delete[] data;
	capacity = new_size;
}