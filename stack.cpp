#include "stack.h"
#include <stdlib.h>
#include <iostream>

LinkedStack::LinkedStack()
{
	top = nullptr;
	len = 0;
}

int LinkedStack::size()
{
	return len;
}

bool LinkedStack::isEmpty()
{
	return len == 0;
}

void LinkedStack::insert_front(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	if (isEmpty()) { // 이 데이터가 최초 Push 인 경우
		top = node;
	}
	else {
		node->next = top; // top을 교체해준다.
		top = node;
	}
	len++;
}

int LinkedStack::delete_front()
{
	Node* temp;
	
	if (isEmpty()) {
		std::cout << "스택이 비었습니다." << std::endl;
		return -99999;
	}

	int popData = top->data;
	temp = top;
	top = top->next; // top을 반환해줌
	free(temp);
	len--;
	return popData;
}

int LinkedStack::serach(int data)
{
	Node* temp = top;

	for (int i = 0; temp != nullptr; i++) {
		if (data == temp->data)
			return len - i;
		temp = temp->next;
	}

	std::cout << "값을 찾지 못했습니다." << std::endl;
	return -99999;
}

void LinkedStack::print_list()
{
	Node* temp = top;

	while (temp != nullptr) {
		std::cout << temp->data << std::endl;
		temp = temp->next;
	}
}
