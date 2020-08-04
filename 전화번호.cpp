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

bool solution(vector<string> phone_book) {
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 0; i<phone_book.size()-1; i++)
    {
        if(phone_book[i]==phone_book[i+1].substr(0,phone_book[i].size()))
            return false;
    }
    return true;
}

int main()
{
    vector<string> phone{"119", "97674223", "1195524421"};
    cout<< solution(phone) << endl;
    
}
