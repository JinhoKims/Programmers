#include<iostream>
using namespace std;


class Weapon {
public:
	  virtual void func(int v) {
		cout << "weapon" << endl;
	}
};

class Gun : public Weapon {
public:
	 void func(double k)  {
		cout << "gun" << endl;
	}
};

class AK : public Gun {
public:
	void func(int x) override  {
		cout << "AK" << endl;
	}
};

int main() {

	Weapon * wps = new AK();
	wps->func(31.25);
	
}