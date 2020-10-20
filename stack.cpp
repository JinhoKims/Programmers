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

	if (isEmpty()) { // �� �����Ͱ� ���� Push �� ���
		top = node;
	}
	else {
		node->next = top; // top�� ��ü���ش�.
		top = node;
	}
	len++;
}

int LinkedStack::delete_front()
{
	Node* temp;
	
	if (isEmpty()) {
		std::cout << "������ ������ϴ�." << std::endl;
		return -99999;
	}

	int popData = top->data;
	temp = top;
	top = top->next; // top�� ��ȯ����
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

	std::cout << "���� ã�� ���߽��ϴ�." << std::endl;
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
