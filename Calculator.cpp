//
//  Calculator.cpp
//  New String Multiple Math
//
//  Created by Batuhan Aydın on 25.11.2018.
//  Copyright © 2018 i.Batuhan Aydın. All rights reserved.
//

#include "Calculator.hpp"
#include "Functions.hpp"
#include <iostream>
#include <string>

using namespace std;
//--------------------------------
Calculator::Calculator(string a)
{
    set_string(a).locate_opt().seperate_nums().make_operation().result_print();
}

Calculator & Calculator::set_string(string a)
{
    delete_blank(&a);
    comma_to_dot(&a);
    doubleplusandminus(&a);
    control(&a);
    input = a;
    size = input.size();
    return *this ;
}

//---------------------------------------
Calculator & Calculator::locate_opt(void)
{
    
        
    output = input.substr(0,size);
    output.insert(0,"(");
    numberofopt = 0;
    int last_loc_opt = -1;
    int k=0;
    
    for(int i=0;i<size;i++)
    {
        if(is_number(input[i]) == 0 && i != 0 && last_loc_opt+1 != i)
           {
               numberofopt++;
               set_opt(i,input[i]);
               last_loc_opt = i;
               k = i+ 2*(numberofopt);
               output.insert(k-1,")");
               output.insert(k+1,"(");
           }
    }
    //cout << "Operator Number : "<< numberofopt<<endl;
    return *this;
}

void Calculator::set_opt(int a, char b)
{
    opt_loc[numberofopt-1] = a;
    opt[numberofopt-1] = b;
}
//-----------------------------------------
Calculator & Calculator::seperate_nums()
{
    total_numberofnum = numberofopt +1;
    
    int num_start = 0;
    int num_end = opt_loc[0];
    int num_size = num_end-num_start;
    set_nums(0,0,convert(input.substr(num_start,num_size)));
    
    for(int i=0;i<numberofopt;i++)
    {
        num_start = opt_loc[i]+1;
        num_end = opt_loc[i+1];
        num_size = num_end - num_start;
        set_nums(i+1,num_start,convert(input.substr(num_start,num_size)));
    }
    return *this;
}

void Calculator::set_nums(int a,int b,double c)
{
    num_loc[a] = b;
    num[a] = c;
}
//------------------------------------------

Calculator & Calculator::test_print()
{
    for(int i=0;i<total_numberofnum;i++)
    {
        cout <<i+1<<". num = " << num[i] <<endl;
        if(i<numberofopt)
        cout <<i+1<<". opt = " << opt[i] <<endl;
    }
    return *this;
}

Calculator & Calculator::result_print()
{
    cout << output;
    cout << ") = " << result<<endl;
    return *this;
}

Calculator & Calculator::make_operation()
{
    int i=0;

    make_calculate(num[i],num[i+1],opt[0],&result);
    //cout << "1. and 2 number operation = " <<result<<endl;
    for(i=1;i<numberofopt;i++)
    {
        make_calculate(result, num[i+1], opt[i], &result);
    }
    return *this;
}









