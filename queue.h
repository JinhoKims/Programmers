#pragma once
#include "Node.h"

class LinkedQueue {
public:

	Node* front, * rear;
	int len;

	LinkedQueue(); 
	int size(); 
	bool isEmpty(); 
	void insert_last(int data); 
	int delete_front();
	int serach(int data);
	void print_list();
};