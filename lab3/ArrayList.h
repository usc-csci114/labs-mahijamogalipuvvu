#ifndef __ARRAYLIST_H__
#define __ARRAYLIST_H__
#include <stdexcept>
#include "List.h"

template <typename T>
class ArrayList : public List<T> {
public:
	ArrayList();
	void append(T v);
	void insert(size_t idx, T v);
	T at(size_t idx);
	void set(T v);
	void remove(size_t idx);
	size_t find(T v);
	size_t size();
	bool empty();

private:
	void resize(); //double the size of the array and copy the items
	size_t m_capacity;
	size_t m_size;
	T* data;
};

template <typename T>
ArrayList<T>::ArrayList()
{
	data = new T[10]; 

	m_size = 10; 	
	m_capacity = 10; 
}

template <typename T>
void ArrayList<T>::append(T v)
{
	if(m_size == m_capacity)
		resize(); 
	
	data[m_size++] = v; 

}

template <typename T>
void ArrayList<T>::insert(size_t idx, T v)
{
	if (idx > m_size) 
    	throw std::out_of_range("index is not within the possible range :(");
    
    if (m_size == m_capacity) 
        resize();
    
	for (size_t i = m_size; i > idx; --i) {
        data[i] = data[i - 1];
    }
	data[idx] = v;
	m_size++;  
	
}

template <typename T>
T ArrayList<T>::at(size_t idx)
{
	if (idx >= m_size) 
    	throw std::out_of_range("index is not within the possible range :(");

    return data[idx];
	
}

template <typename T>
void ArrayList<T>::set(T v)
{
	if (idx >= m_size) 
    	throw std::out_of_range("index is not within the possible range :(");
    
	if (empty())  
    	throw std::out_of_range("list is empty!");
    
	data[m_size - 1] = v;   

	
}

template <typename T>
void ArrayList<T>::remove(size_t idx)
{
	 if (idx >= m_size)
    	throw std::out_of_range("index is not within the possible range :(");
    
    for (size_t i = idx; i < m_size - 1; ++i) 
        data[i] = data[i + 1];
    
    m_size--; 
}
	

template <typename T>
size_t ArrayList<T>::find(T v)
{
	for (size_t i = 0; i < m_size; i++) 
		if (data[i] == v) 
			return i;  


    return -1;
	
}

template <typename T>
size_t ArrayList<T>::size()
{
	return m_size;
}

template <typename T>
bool ArrayList<T>::empty()
{
	return m_size = 0;

}

template <typename T>
void ArrayList<T>::resize()
{
	m_capacity *= 2; 
    T* newData = new T[m_capacity]; 

    for (int i = 0; i < m_size; i++) 
        newData[i] = data[i]; 

    delete[] data; 
    data = newData; 
	
}
#endif
