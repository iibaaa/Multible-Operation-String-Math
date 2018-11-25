//
//  Functions.cpp
//  New String Multiple Math
//
//  Created by Batuhan Aydın on 25.11.2018.
//  Copyright © 2018 i.Batuhan Aydın. All rights reserved.
//

#include "Functions.hpp"
#include <iostream>
#include <string>

void delete_blank(std::string *str)
{
    for(int i= 0;i<(*str).size();i++)
    {
        if((*str).at(i) == ' ')
        {
            (*str).erase(i,1);
            i--;
        }
    }
}

void comma_to_dot(std::string *str)
{
    for(int i=0;i<(*str).size();i++)
    {
        if((*str).at(i) == ',')
            (*str).replace(i,1,1,'.');
    }
}

void control(std::string *std)
{
    unsigned long int a = (*std).size()-1;
    if(is_number((*std)[a]) == 0)
       {
           //std::cout << "Hatali İslem Girdisi."<<std::endl;
           //std::cout << "Hata duzeltiliyor."<<std::endl;
           (*std).erase(a,1);
       }
}

int is_number(char ch)
{
    if( ('0'<=ch && ch<='9') || ch == '.')
        return 1;
    else
        return 0;
}

double convert(std::string str)
{
    return stod(str);
}

void make_calculate(double a,double b,char c,double *result)
{
    switch(c)
    {
        case '+':
            *result = a + b;
            break;
            
        case '-':
            *result = a - b;
            break;
            
        case '*':
            *result = a * b;
            break;
            
        case '/':
            *result = a / b;
            break;
            
        default:
            *result = 1001;
            break;
    }
}
