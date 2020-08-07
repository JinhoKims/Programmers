#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

int main()
{
	thread T1, T2, T3;
	mutex mtx_lock;
	int number = 0;

	T1 = thread([&]() {
		for (int i = 0; i < 5; i++)
		{
			mtx_lock.lock();
			cout << "Thread 1 num : " << number++ << endl;
			mtx_lock.unlock();
		}
	});

	T2 = thread([&]() {
		for (int i = 5; i < 10; i++)
		{
			mtx_lock.lock();
			cout << "Thread 2 num :" << number++ << endl;
			mtx_lock.unlock();
		}
	});

	T3 = thread([&]() {
		for (int i = 10; i < 15; i++) {
			lock_guard<mutex> guard(mtx_lock);
			cout << "Thread 3 num : " << number++ << endl;
		}
	});

	
	T1.join();
	T2.join();
	T3.join();

	return 0;
}