#include "queue.h"
#include <stdlib.h>
#include <iostream>

LinkedQueue::LinkedQueue()
{
	front = nullptr;
	rear = nullptr;
	len = 0;
}

int LinkedQueue::size()
{
	return len;
}

bool LinkedQueue::isEmpty()
{
	 return len == 0;
}

void LinkedQueue::insert_last(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (isEmpty()) { // �� �����Ͱ� ���� add �� ���
        front = rear = node;
    }
    else { // �ƴҰ��
        rear->next = node; // rear�� node��ũ�� �߰��ϰ�
        rear = rear->next; // �����͸� �־��ش�.
    }
    len++;
}

int LinkedQueue::delete_front()
{
    if (isEmpty()) {
        std::cout << "ť�� ������Դϴ�." << std::endl;
        return -99999;
    }

    Node* dele = front;
    int data = dele->data;
    front = dele->next; // ��ũ ��ü �۾�
    free(dele);
    len--;
    return data;
}

int LinkedQueue::serach(int data)
{
    Node* temp = front;

    for (int i = 0; temp != nullptr; i++) {
        if (data == temp->data)
            return ++i;
        temp = temp->next;
    }

    std::cout << "���� ã�� ���߽��ϴ�." << std::endl;
    return -99999;
}

void LinkedQueue::print_list()
{
    Node* temp = front;

    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
