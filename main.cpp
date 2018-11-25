//
//  main.cpp
//  New String Multiple Math
//
//  Created by Batuhan Aydın on 25.11.2018.
//  Copyright © 2018 i.Batuhan Aydın. All rights reserved.
//

#include <iostream>
#include <string>

#include "Calculator.hpp"

using namespace std;

int main(void)
{
    string input;
    cout << "Enter ('E' for Exit) : ";
    getline(cin,input);
    while(input != "e" && input != "E")
    {
        Calculator c1(input);
        cout << "Enter ('E' for Exit) : ";
        getline(cin,input);
    }
    
    return 0;
}
