#include<iostream>
#include<memory>
using namespace std;

class node
{
public:
	node(int && a) :data(std::move(a)) {
		cout << "�̵������� ȣ��" << endl;
		pys = "abcdef";
	};
	node(int a, int p) :data(a) {
		cout << "�Ϲݻ����� ȣ��" << endl;
	}
	node(node& a) { cout << "��������� ȣ��" << endl; }
	int data;
	weak_ptr<node> next;
	string pys;
	node() { cout << "node()" << endl; }
	~node() { cout << "~node()" << endl; }

	node& operator=(node&& other) noexcept {
		this->pys = move(other.pys);
		cout << "�̵����Կ����� ȣ��" << endl;
		return *this;
	}

	node& operator+(node* other) { // �����͸� ������� ������ �����ε��� �Ϸ��� ���ڸ� �����ͷ� �����Ѵ�.
		this->data += other->data;
		cout << " �����Ϳ� operator+ ȣ��" << endl;
		return *this;
	}

	node& operator+(node & other) { // �Ϲ� ������ �����ε� (�� �����Ϳ�)
		this->data += other.data;
		cout << " ��ü�� operator+ ȣ��" << endl;
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
	*n = move(*p); // �����Ͱ� ���Կ����� �����ε��� ȣ���Ϸ��� ��������(*)�� �ؾ� �Ѵ�.
	cout << " n : " << n->pys << endl;
	cout << " p : " << p->pys << endl;
	n->operator+(p); // ������ �����ε� case 1
	*n + *p;
	node n1; node n2;
	n1 + n2; // ������ �����ε� case 2
	n1 + &n2;
	*n = n - p;
}

void test2()
{
	int&& q = 10;
	const int& b = std::move(q); // Rvalue ���� �� Lvalue(���ε�)
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
		cout << "wp1 is alive" << endl; // ��ü�� ���� sp2�� ���� ���̱⿡ else�� ����ȴ�.

}