//
//  main.cpp
//  BaekJoonCpp
//
//  Created by 김진호 on 2020/07/27.
//  Copyright © 2020 myProject. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, int> m;

    for(vector<string> vec : clothes)
    {
        m[vec[1]]+=1;
    }

    for(map<string,int>::iterator iter = m.begin(); iter!=m.end(); iter++)
    {
        answer*=iter->second+1;
    }
    return answer-1;
}

int main()
{
    vector<vector<string>> spy{{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};
    cout << solution(spy) << endl;
}
