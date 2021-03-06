#include<iostream>
#include<functional>
using namespace std;

class Test {
public:
	Test(int n):data(n) {};
	void display_greeting() {
		cout << "hello world" << endl;
	}
	void display_number(int i) {
		data = i;
		cout << "number : " << data << endl;
	}
	int data;
};


int main() {
	Test test(300);

	auto greet = mem_fn(&(Test::display_greeting));
	greet(test);

	auto print_num = mem_fn(&Test::display_number);
	print_num(test, 80);

	auto access_data = mem_fn(&Test::data);
	cout << access_data(test) << endl;

	std::function<void(Test&, int)> f_display_num = &Test::display_number;
	f_display_num(test, 777);

	cout << access_data(test) << endl; 
}
