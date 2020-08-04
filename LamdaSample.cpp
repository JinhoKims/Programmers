//
// 람다식 실습예제
#include <iostream>
using namespace std;

template<typename T> // <T cmp> 템플릿은 람다함수의 몸체를 받기위해 사용.
void SimnpleSort(int a, int b, T cmp){
    if(cmp(a,b)) // 넘겨온 선언된 람다식을 호출(a,b)한다. But, 만약 람다식을 main에서 호출했을경우 if(cmp)로 해서 반환값을 읽을 수 있다.
        cout << "Complet" << endl;
}




int main(){
   // 코드 설명 : 오름차순(Up), 내림차순(Down) 정렬을 람다식으로 템플릿으로 받아 호출하여 구현

    SimnpleSort(129, 41, [](int a, int b)->bool{return a>b? true:false;}); // 함수 호출의 3번째 인자로 람다식을 선언한다.((호출)은 함수안에서 함!!)
    SimnpleSort(431, 819, [](int a, int b)->bool{return a<b? true:false;}); // (431<819)가 참이면, true 반환
    
    /* 람다의 특징 : 조건부 인라인화가 가능하다.(상수로 만들어졌을 때) <- 람다는 이름은없지만 컴파일러가 "고유한 객체"로 취급함
       인라인화가 가능할 때 : auto 변수로 람다식을 받을 때, auto는 컴파일 시에 하나의 타입으로 고정됨(유저가 다른 자료형으로 변경할 수 없기에)
       인라인화가 불가능할 때 : 1. 람다를 포인터로 전달할 때, (함수 포인터는 <다른 주소>를 참조할 수 있기때문에(변수)) 인라인화가 불가능
       2. std::function<> 을 사용할 때, 명확한 타입을 알 수 없는 <탬플릿 객체>이기 때문에 정의가 모호해 인라인화가 불가능
    */
    // 람다는 선언해도 호출()되기 전에, {내용}을 실행시키지 않는다.
    
    int x = 10;
    int v = 2;
    auto l1 = [&](){
        x = 7;
        return x;
    }; // 람다 선언
    
    auto l2 = [&,x = (x += 100)]()mutable{ // x+=100 까지는 외부 x &참조 / x=..., ++x는 람다식 내부의 지역변수 x(외부 &참조가 아님)
        cout << ++v << endl;
        return x; // return x도 람다식 내의 지역변수임
    };
    cout  << endl << l2() << endl;
    cout << v << endl;
    cout << l1() << endl; // 람다 실행
    
    
    auto l3 = [](){return 43;};
    cout << l3() << endl;
    auto l4 = [](){return 44;}();
    cout << l4 << endl;
    
    int(*ptr)() = [](){return 41;};
}
