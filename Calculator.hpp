//
//  Calculator.hpp
//  New String Multiple Math
//
//  Created by Batuhan Aydın on 25.11.2018.
//  Copyright © 2018 i.Batuhan Aydın. All rights reserved.
//

#ifndef Calculator_hpp
#define Calculator_hpp

#include <string>

#define SizeN 100
#define SizeO 100

class Calculator
{
private:
    std::string input;
    std::string output;
    
    double result;
    
    long unsigned int size;
    
    double num[SizeN];
    int num_loc[SizeN];
    int total_numberofnum;
    
    char opt[SizeO];
    int opt_loc[SizeO];
    int numberofopt;
    
    
public:
    
    Calculator(std::string);
    Calculator& set_string(std::string);
    Calculator& locate_opt(void);
    void set_opt(int,char);
    Calculator& seperate_nums(void);
    void set_nums(int,int,double);
    Calculator& test_print();
    Calculator& result_print();
    
    Calculator& make_operation(void);
};

#endif /* Calculator_hpp */
