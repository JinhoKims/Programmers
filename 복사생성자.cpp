#include<iostream>
using namespace std;

class Node {

public:
	Node() {
		cout << "일반생성자 호출" << endl;
	}
	Node(Node& others) { // 인수로 일반 변수를 받는다.
		cout << "복사생성자 호출" << endl;
	}
	
	Node& operator=(Node& other) {
		cout << "	복사대입연산자& 호출" << endl;
		return *this;
	}
	Node * operator=(Node * other) {
		cout << "복사대입연산자* 호출" << endl;
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
	int ic = ib; // 복사생성자는 값만 복사받는다. (주소가 아님)
	ia = 80;
	cout << "ia : " << ia << "ib : " << ib << "ic : " << ic << endl;
	cout << "Address : " << a << " " << &b << " " << a2 << " " << &b2 << endl;
}