#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__
#include <stdexcept>
#include "List.h"

template <typename T>
class Node {
	public: 
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
	void set(size_t idx, T v);
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
	Node<T>* newItem = new Node<T>; 
	newItem->value = v; 
	newItem->next = NULL; 
	if(head == NULL){
		head = newItem; 
		tail = newItem;  
	}
	else{
		tail->next = newItem; 
		tail = newItem; 
	} 

}

template <typename T>
void LinkedList<T>::insert(size_t idx, T v)
{
	if(idx > m_size){
		throw std::out_of_range("Invalid index"); 
	}
	Node<T>* newItem = new Node<T>;
	newItem->value = v; 
	newItem->next = NULL;
	if(idx == 0){
		newItem->next = head; 
		head = newItem;       
        if (m_size == 0) {    
            tail = newItem;
        }
	}
	else{
		Node<T>* curr = head; 
		for(int i=0; i < idx -1; i++){
			curr = curr->next; 
		}
		newItem->next = curr->next; 
		curr->next = newItem; 
		if (newItem->next == NULL) { 
            tail = newItem;
        }
	}
	m_size++; 
}

template <typename T>
T LinkedList<T>::at(size_t idx)
{
	//return value at this index 
	if (idx >= m_size) {
        throw std::out_of_range("Index out of range");
    }
	Node<T>* curr = head; 
	for(int i = 0; i < idx; i++){
		curr = curr->next; 
	}
	return curr->value; 
}

template <typename T>
void LinkedList<T>::set(size_t idx, T v)
{
  	if (idx >= m_size) {
        throw std::out_of_range("Index out of range");
    }
    Node<T>* curr = head;
    for (size_t i = 0; i < idx; i++) {
        curr = curr->next;
    }
    curr->value = v;	
}

template <typename T>
void LinkedList<T>::remove(size_t idx)
{
	if (idx >= m_size) {
        throw std::out_of_range("Index out of range");
    }
	if(idx == 0){
		Node<T>* temp = head; 
		head = head->next; 
		if(head == NULL){
			tail = NULL; 
		}
		delete temp;  
	}
	else if(idx == m_size - 1){
		Node<T>* curr = head;
        while (curr->next != tail) {
            curr = curr->next;
        }
        delete tail;  
		tail = curr; 
        curr->next = NULL; 
	}
	else{
		 Node<T>* curr_prev = head;
		for(int i=0; i < idx - 1; i++){
			curr_prev = curr_prev->next; 
		}
		Node<T>* temp = curr_prev->next; //this is the node to be removed 
		curr_prev->next = temp->next; 
		delete temp; 
		//need to delete curr, make what was before it point to what was after it (curr->next)
		//curr_prev is item before it 
	}
	m_size--;  
}

template <typename T>
size_t LinkedList<T>::find(T v)
{
	//return index it's at 
	size_t idx = 0; 
	Node<T>* temp = head;  
	if(temp == NULL) {
        throw std::out_of_range("List is empty");
    }
	while(temp != NULL){
		if (temp->value == v) {
            return idx; 
        } 
		temp = temp->next; 
		idx++;
	}
	throw std::out_of_range("Value not found"); 
}

template <typename T>
size_t LinkedList<T>::size()
{
	return m_size; 
}

template <typename T>
bool LinkedList<T>::empty()
{
	if(head == NULL && tail == NULL){
		return true; 
	} 
	else{
		return false; 
	}
}

#endif
