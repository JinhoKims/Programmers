#include<iostream>

using namespace std;

extern int a;
void func(int, int); // �Լ� ������ extern Ű���尡 �ٿ��ٰ� �����Ѵ�.
extern int ass(int v);

static void hhas() {
	cout << 21 << endl;
}

void show() {
	cout << "hi" << endl;
}

int main() {
	cout << a << endl;
	int x = 11;
	int v = 14;
	func(x, v);
	cout << ass(7889) << endl;
}