#pragma once
#include "Node.h"

class LinkedStack {
public:

	Node* top;
	int len;

	LinkedStack();
	int size();
	bool isEmpty();
	void insert_front(int data);
	int delete_front();
	int serach(int data);
	void print_list();
};