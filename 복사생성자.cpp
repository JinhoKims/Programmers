#include<iostream>
using namespace std;

class Node {

public:
	Node() {
		cout << "�Ϲݻ����� ȣ��" << endl;
	}
	Node(Node& others) { // �μ��� �Ϲ� ������ �޴´�.
		cout << "��������� ȣ��" << endl;
	}
	
	Node& operator=(Node& other) {
		cout << "	������Կ�����& ȣ��" << endl;
		return *this;
	}
	Node * operator=(Node * other) {
		cout << "������Կ�����* ȣ��" << endl;
		return this;
	}
};

Node other;

Node* test1() {
	return &other;
}

Node& test2() {
	return other;
}

Node test3() {
	return other;
}


int main() {
	cout << endl;

	Node* a = test1();
	Node& b = test2();

	Node* a2 = &test2();
	Node& b2 = *test1();

	cout << "Case C : ";
	Node c = test2();

	cout << "Case D : ";
	Node d;
	d = test2();

	cout << "Case E :";
	Node* e = a; 
	*e = test1();

	cout << "Case F : ";
	test3();


	int ia = 7;
	int& ib = ia;
	int ic = ib; // ��������ڴ� ���� ����޴´�. (�ּҰ� �ƴ�)
	ia = 80;
	cout << "ia : " << ia << "ib : " << ib << "ic : " << ic << endl;
	cout << "Address : " << a << " " << &b << " " << a2 << " " << &b2 << endl;
}