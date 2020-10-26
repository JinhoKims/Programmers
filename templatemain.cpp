#include <iostream>
#include <vector>
#include "templateh.h"

template<typename T>
using nocopeKeys = std::vector<T>; // Aliasing Template

template<typename T=int>
constexpr T pi = T(3.1415); // Variable Template

template<>
float foo<float>(float a) {
	std::cout << " hi! im float " << std::endl;
	return a * a;
}

template<typename A, typename B, typename G=int>
A fos(A a, A f);

template<> // Template Specialization
float fos<float, int>(float a, float f) // Template argument xplicitly specified
{
	return a * f;
}

int main() {

	nocopeKeys<double> intKeys;
	intKeys.push_back(41.231);

	std::cout << foo<int>(101) << std::endl;

	std::cout << pi<> << std::endl;

	std::cout << foo(97.65f) << std::endl;

	std::cout << fos<float, int>(57.87f, 48.24f) << std::endl;
}

