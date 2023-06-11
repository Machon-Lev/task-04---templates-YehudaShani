#pragma once

#include <iostream>
#include <list>
#include <exception>

template <typename T>
struct MyComparator {
	bool operator()(const T& lhs, const T& rhs) const
	{
		return lhs < rhs;
	}

};


// any templates?
template <typename T>
class PriorityQueue {
   
public:
	
   // You need to complete the implement : 
	void push(const T i); 
	T pull();

private:
// add relevant data members
	std::list<T> m_list;
};

template <typename T>
void PriorityQueue<T>::push(const T i)
{
	// find correct place to insert
	MyComparator<T> comp;

	auto it = m_list.begin();
	while (it != m_list.end() && comp(i, *it))
	{
		++it;
	}
	m_list.insert(it, i);
}

template <typename T>
T PriorityQueue<T>::pull()
{
	if (m_list.empty())
	{
		throw std::exception("list is empty");
	}
	T i = m_list.front();
	m_list.pop_front();
	return i;
}


