#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <ostream>

using namespace std;

template <typename T> class Node{

public:
	T data;
	Node<T> *next;

	Node(T data, Node<T>* next = nullptr){
		this->data = data;
		this->next = next;	
	}

	friend ostream&operator<<(ostream &out, const Node<T> &node){
		out << "Data : " << node.data << "\n";
		return out;
	}
};



#endif
