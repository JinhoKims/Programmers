#include<iostream>
using namespace std;

const string func()
{
	string s = "absd";
	return s;
}

int main() {
	
	string ptr1 = "asdd";
	const string & rptr = ptr1;
	const string ptr2 = std::move(rptr);

	cout << ptr1 << endl;
	cout << rptr << endl;
	cout << ptr2 << endl;

	string str = "asfd";
	string && str2 = std::move(str);
	
	cout << "--------" << endl;
	cout << str << endl << str2 << endl;

	// const ���� move()���ڷ� ���� ��, �Ǵ� move()�� �޴��ڰ� rvalue reference�� ��� �����ʹ� �̵����� �ʰ� ����ȴ�.

}