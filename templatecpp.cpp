template<typename T>
T foo(T a) {
	return a * a;
}

template int foo<int>(int); // ����� ���ø� �ν��Ͻ�ȭ
template double foo<double>(double);