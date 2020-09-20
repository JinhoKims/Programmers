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
	node() { cout << "node() : " << this << endl; }
	~node() { cout << "~node() : " << this << endl; }

	node & operator=(node&& other) noexcept { // ��ȯ���� &�� ����� �����ϸ� �߰����� ���簡 �Ͼ��.
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
		cout << "��ä�� operator- ȣ��" << endl;
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

	cout << endl << "--- �̵������� �� �̵����Կ������� ��� ����� �� ---" << endl;
	cout << "-------------" << endl;
	node&& cs1 = (n - p);			// (n-p)�� R-value�� ��ȯ�ϱ⿡ R-value Reference�� ����ִ� ���� �ʿ��ϴ�. (�ƴϸ� �Ҹ��ڰ� ȣ��Ǳ⿡)
	cout << "cs1() : " << &cs1 << endl;
	cout << "-------------" << endl;
	*n = n - p;
	cout << "���ӽû����� �����Ϸ�" << endl;
	cout << "-------------" << endl;
	node cs2; // Node() : ������ ȣ��
	cs2 = (n - p);
	cout << "���ӽû����� �����Ϸ�" << endl;
	(n - p); // �ǹ̾����� �����Ϸ��� �ڵ����� �����!
	cout << "-------------" << endl;
	*n = std::move(*p);
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