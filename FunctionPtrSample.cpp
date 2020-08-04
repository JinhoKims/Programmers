#include <iostream>
using namespace std;

bool Up(int x, int y){return x>y? true:false;}
bool Down(int x, int y){return x<y? true:false;}
bool (*ptr)(int, int); // pointer
void SimpleSort(int x, int y, bool(*ptr)(int,int)){ // 함수의 3번째 인수(파라미터)로 (함수포인터) 선언
    cout << ptr(x,y) << endl;
}

int main(){
    
    bool(*ptr)(int,int) = Up; // 함수 포인터 ptr
    
    // 코드 설명 : 오름차순(Up), 내림차순(Down) 정렬을 함수 포인터를 이용해 구현.
    SimpleSort(13, 12, Up); // 호출함수의 3번째 아규먼트로 함수(Up)를 포인터에 대입한다.
    SimpleSort(12, 13, Down); // Down 함수가 대입된 포인터는 x<y 연산을 한다.
  
}
