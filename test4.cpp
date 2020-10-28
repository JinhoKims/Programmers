#include<iostream>
using namespace std;


class Weapon {
public:
	  virtual void func(int v) {
		cout << "Weapon" << endl;
	}
};

class Gun : public Weapon {
public:
	 virtual void func(double k) {
		cout << "Gun" << endl;
	}
};

class AK : public Gun {
public:
	void func(int x) override {
		cout << "Weapon-AK" << endl;
	}

	void func(double x) override {
		cout << "Gun-AK" << endl;
	}
};

int main() {

	Weapon * wps = new AK();
	Gun * wps2 = new AK();

	wps->func(41);
	wps2->func(234.52);
	
}