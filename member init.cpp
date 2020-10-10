#include<iostream>
using namespace std;

class milk {
public:
    int age;

    milk() = default; //  { cout << "기본 생성자 호출" << endl; } ※ default 키워드로 생성자를 만들 경우, age가 0으로 초기화 안되니 직접 초기화 해줘야됨

    milk(int age) :age{ age } {
        cout << "생성자 호출" << endl;
    }

    ~milk() { cout << "삭제 " << this << endl; }

    //milk& operator=(milk & p) {
    //      cout << "연산자 오버로딩1 발생" << endl;
    //      this->age = p.age;
    //      return *this;
    //}

    milk operator=(milk p) {
        cout << "연산자 오버로딩2 발생" << endl;
        this->age = p.age;
        return *this;
    }
};

class cow{
public:
    milk son;

    cow(int age) { // case 1
        cout << "cow 생성자 호출" << endl;
        milk temp;
        temp.age = 37; // default로 인한 멤버 직접 초기화 진행
        son = temp; // "연산자 오버로딩 1 or 2 발생
        
      //  son = milk(age); // "only 연산자 오버로딩2 발생"
    }                               

    //cow(int age) :son(milk(age)) { cout << "cow 생성자 호출" << endl; } // case 2 is better
};


int main() {
    cow cowf(31);
}