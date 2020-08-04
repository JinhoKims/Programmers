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
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    
    for(int i=0; i <participant.size(); i ++){
        if(participant[i]!=completion[i])
            return participant[i];
    }
    
    return participant[0];
}


int main(int argc, const char * argv[]) {

    vector<string> part{"mislav","stanko","mislav","ana"};
    vector<string> com{"stanko", "ana","mislav",};

    cout << solution(part, com) << endl;
    return 0;
}


