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
    for(long int i=0;i<(*std).size();i++)
    {
        if(   ((*std)[i] == '+' || (*std)[i] == '-') && ((*std)[i+1] == '/' || (*std)[i+1] == '*')      )
        {
            (*std).erase(i,1);
            i--;
        }
    }
    unsigned long int a = (*std).size()-1;
    if(is_number((*std)[a]) == 0)
       {
           //std::cout << "Hatali İslem Girdisi."<<std::endl;
           //std::cout << "Hata duzeltiliyor."<<std::endl;
           (*std).erase(a,1);
       }
    if((*std)[0] == '*' || (*std)[0] == '/')
    {
        std::cout << "Wrong first input deleted." <<std::endl;
        (*std).erase(0,1);
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
    if(str[0] == '*')
    {
        str.erase(0,1);
        std::cout << "Error Wrong Symbol : '*' "<<std::endl<<"Symbol Ignored"<<std::endl;
    }
    else if(str[0] == '/')
    {
        str.erase(0,1);
        std::cout << "Error Wrong Symbol : '/' "<<std::endl<<"Symbol Ignored"<<std::endl;
    }
    return stod(str);
}




void doubleplusandminus(std::string *a)
{
    for(long int i=0;i<(*a).size();i++)
    {
        if( (*a)[i] == '+' && (*a)[i+1] == '+')
        {
            (*a).erase(i+1,1);
            i--;
        }
        if( (*a)[i] == '-' && (*a)[i+1] == '-')
        {
            (*a).erase(i,2);
            (*a).insert(i,"+");
            i--;
        }
        if( ((*a)[i] == '+' && (*a)[i+1] == '-' )|| ((*a)[i] == '-' && (*a)[i+1] == '+'))
        {
            (*a).erase(i,2);
            (*a).insert(i,"-");
            i--;
        }
    }
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
