#include<iostream>
#include<vector>
using namespace std;

class Animal
{
public:
	virtual void sepak() {}

private:
	double anim;
};

class Lion : public Animal
{
public:

private:
	double lion;

};

class King : public Lion
{
public:
	void sepak() { cout << 15 << endl; };

private:
	double lion;
};

namespace Tz {
	int x;
}

namespace Tz {
	int v;
}

using my_vector = std::vector<Animal>; // using의 사용법

int main()
{
	Lion * anime = new King();
	anime->sepak();

	my_vector a;

	a.push_back(King());
	a.push_back(Lion());
	a.push_back(*anime);
}
