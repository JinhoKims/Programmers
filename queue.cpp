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
    if (isEmpty()) { // 이 데이터가 최초 add 인 경우
        front = rear = node;
    }
    else { // 아닐경우
        rear->next = node; // rear에 node링크를 추가하고
        rear = rear->next; // 데이터를 넣어준다.
    }
    len++;
}

int LinkedQueue::delete_front()
{
    if (isEmpty()) {
        std::cout << "큐는 빈공간입니다." << std::endl;
        return -99999;
    }

    Node* dele = front;
    int data = dele->data;
    front = dele->next; // 링크 교체 작업
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

    std::cout << "값을 찾지 못했습니다." << std::endl;
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
