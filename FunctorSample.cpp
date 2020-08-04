#include <iostream>
using namespace std;

class Up{
public:
    bool operator()(int a, int b){ // Functor, 이항 술어
        return a>b?true:false;
    }
};

class Down{
public:
    bool operator()(int a, int b){
        return a<b?true:false;
    }
};

template<typename T> // 템플릿은 각 클래스별 선언된 객체를 받아서 Functor()를 호출하기위해 사용.
void SimpleSort(int x, int y, T cmp){ // 3번째 인수로 대입용 템플릿 객체 선언
    cout << cmp(x,y) << endl; // cmp() 오버로딩 된 함수객체를 호출 (Up or Down)
}


int main(){
    // 코드 설명 : 오름차순(Up), 내림차순(Down) 정렬을 함수 객체()를 이용해 구현.
    Up up; Down dn; // 차순 정렬용 객체(인자로 들어감)
    
    SimpleSort(152, 41, up); // 3번째 인자로 객체를 넘겨줘서 함수안에서 함수객체를 실행하게 한다.
    SimpleSort<Down>(51, 829, dn); // 명시적 템플릿 인수<Down>로 호출
}

// 함수포인터 : 간결, 명확, 인라인 불가능
// 함수 객체 : 인라인화(호출이 아닌 main에서 진행) 가능, 코드 길이가 길어짐
