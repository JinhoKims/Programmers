#include<iostream>

using namespace std;

extern int a;
void func(int, int); // 함수 선언은 extern 키워드가 붙였다고 가정한다.
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