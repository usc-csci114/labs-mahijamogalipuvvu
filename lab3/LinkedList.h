#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__
#include <stdexcept>
#include "List.h"

template <typename T>
class Node {
	T value;
	Node* next;
};

template <typename T>
class LinkedList : public List<T> {
public:
	LinkedList();
	void append(T v);
	void insert(size_t idx, T v);
	T at(size_t idx);
	void set(T v);
	void remove(size_t idx);
	size_t find(T v);
	size_t size();
	bool empty();

private:

	size_t m_size;
	Node<T>* head;
	Node<T>* tail;
};

template <typename T>
LinkedList<T>::LinkedList()
{
	m_size = 0; 
	head = NULL; 
	tail = NULL; 
}

template <typename T>
void LinkedList<T>::append(T v)
{
	Node<T>* newNode = new Node<T>; 

	newNode->value = v; 
	newNode->next = NULL; 

	if(head == NULL) {
		head = newNode; 
		tail = newNode;  
	} else {
		tail->next = newNode; 
		tail = newNode; 
	} 

	m_size++;

}

template <typename T>
void LinkedList<T>::insert(size_t idx, T v)
{
	if (idx > m_size)
    	throw std::out_of_range("index is not within the possible range :(");
    
    
    Node<T>* newNode = new Node<T>;
	
	newNode->value = v; 
    
    if(idx == 0) { 
		newNode->next = head; 
		head = newItem;
        
        if (m_size == 0)
            tail = newNode;
    } else {
        Node<T>* current = head;
       
	    for (int i = 0; i < idx - 1; i++)  
            current = current->next;
        
        newNode->next = current->next; 
		current->next = newNode 
       
	   if (newNode->next == NULL)
    	    tail = newNode;
        
    }
    m_size++;
}

template <typename T>
T LinkedList<T>::at(size_t idx)
{
	if (idx >= m_size) 
    	throw std::out_of_range("index is not within the possible range :(");
    
	Node<T>* current = head; 

	for(int i = 0; i < idx; i++)
		current = current->next; 
	
	return current->value; 

	
}

template <typename T>
void LinkedList<T>::set(T v)
{
	if (idx >= m_size) 
    	throw std::out_of_range("index is not within the possible range :(");
    
    Node<T>* current = head;
    for (int i = 0; i < idx; i++) {
        current = current->next;
    }
    current->value = v;
	
}

template <typename T>
void LinkedList<T>::remove(size_t idx)
{
	if (idx >= m_size) 
    	throw std::out_of_range("index is not within the possible range :(");
    
    Node<T>* temp;
    
    if (idx == 0){
        temp = head; 
        head = head->next; 

		if(head == NULL)
			tail = NULL;

    } else {
        Node<T>* prev = head;
        for (int i = 0; i < idx; ++i) { 
            prev = prev->next;
        }
        temp = prev->next; 
        prev->next = temp->next; 

        if (temp == tail) {
            tail = prev; 
        }
    }
    
    delete temp;
    m_size--;

	
}

template <typename T>
size_t LinkedList<T>::find(T v)
{
	Node<T>* temp = head;
    for (int i = 0; i < m_size; i++) { 
        if (temp->value == v)
            return i; 
        
        temp = temp->next;
    }
    return -1; 

}

template <typename T>
size_t LinkedList<T>::size()
{
	return m_size; 
	
}

template <typename T>
bool LinkedList<T>::empty()
{
	return m_size == 0;

}

#endif
