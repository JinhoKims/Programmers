#include<iostream>
using namespace std;

class milk {
public:
    int age;

    milk() = default; //  { cout << "�⺻ ������ ȣ��" << endl; } �� default Ű����� �����ڸ� ���� ���, age�� 0���� �ʱ�ȭ �ȵǴ� ���� �ʱ�ȭ ����ߵ�

    milk(int age) :age{ age } {
        cout << "������ ȣ��" << endl;
    }

    ~milk() { cout << "���� " << this << endl; }

    //milk& operator=(milk & p) {
    //      cout << "������ �����ε�1 �߻�" << endl;
    //      this->age = p.age;
    //      return *this;
    //}

    milk operator=(milk p) {
        cout << "������ �����ε�2 �߻�" << endl;
        this->age = p.age;
        return *this;
    }
};

class cow{
public:
    milk son;

    cow(int age) { // case 1
        cout << "cow ������ ȣ��" << endl;
        milk temp;
        temp.age = 37; // default�� ���� ��� ���� �ʱ�ȭ ����
        son = temp; // "������ �����ε� 1 or 2 �߻�
        
      //  son = milk(age); // "only ������ �����ε�2 �߻�"
    }                               

    //cow(int age) :son(milk(age)) { cout << "cow ������ ȣ��" << endl; } // case 2 is better
};


int main() {
    cow cowf(31);
}