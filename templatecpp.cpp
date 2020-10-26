template<typename T>
T foo(T a) {
	return a * a;
}

template int foo<int>(int); // 명시적 템플릿 인스턴스화
template double foo<double>(double);