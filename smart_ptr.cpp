#include<iostream>
#include<memory>
using namespace std;

class node
{
public:
	node(int && a) :data(std::move(a)) {
		cout << "이동생성자 호출" << endl;
		pys = "abcdef";
	};
	node(int a, int p) :data(a) {
		cout << "일반생성자 호출" << endl;
	}
	node(node& a) { cout << "복사생성자 호출" << endl; }
	int data;
	weak_ptr<node> next;
	string pys;
	node() { cout << "node()" << endl; }
	~node() { cout << "~node()" << endl; }

	node& operator=(node&& other) noexcept {
		this->pys = move(other.pys);
		cout << "이동대입연산자 호출" << endl;
		return *this;
	}

	node& operator+(node* other) { // 포인터를 대상으로 연산자 오버로딩을 하려면 인자를 포인터로 선언한다.
		this->data += other->data;
		cout << " 포인터용 operator+ 호출" << endl;
		return *this;
	}

	node& operator+(node & other) { // 일반 연산자 오버로딩 (비 포인터용)
		this->data += other.data;
		cout << " 객체용 operator+ 호출" << endl;
		return *this;
	}

	node* operator- (node* other) {
		this->data -= other->data;
		return this;
	}

};
void test1()
{
	node* n = new node(111); node* p = new node(333);
	*n = move(*p); // 포인터가 대입연산자 오버로딩을 호출하려면 간접연산(*)을 해야 한다.
	cout << " n : " << n->pys << endl;
	cout << " p : " << p->pys << endl;
	n->operator+(p); // 연산자 오버로딩 case 1
	*n + *p;
	node n1; node n2;
	n1 + n2; // 연산자 오버로딩 case 2
	n1 + &n2;
	*n = n - p;
}

void test2()
{
	int&& q = 10;
	const int& b = std::move(q); // Rvalue 참조 → Lvalue(바인딩)
}

void test3()
{
	string abs = "ffase";
	string& rbs = abs;
	abs.clear();
	cout << "rbs : " << rbs << endl;
}

int main() {

	test1(); cout << endl;
	test2(); cout << endl;
	test3(); cout << endl;

	shared_ptr<node> sp1(new node);
	weak_ptr<node> wp1 = sp1;
	auto sp2 = wp1.lock();
	sp1.reset();

	if (wp1.expired())
		cout << "wp1 destroyed " << endl; 
	else
		cout << "wp1 is alive" << endl; // 객체는 아직 sp2가 유지 중이기에 else가 실행된다.

}