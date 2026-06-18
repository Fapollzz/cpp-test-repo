#include "calculator.h"
#include <iostream>
#include <string>
#include <cmath>


bool ReadNumber (Number& result){
        if (!(std::cin >> result)){
               std::cerr << "Error: Numeric operand expected" << std::endl;
             return false;
        }
        return true;
}

bool RunCalculatorCycle ( ){
    Number current_number = 0; //текущее значение калькулятора
    Number saved_number; // сохранённое значение в памяти
    bool number_is_saved = false; // сохранено ли что-либо в памяти
    if(!ReadNumber(current_number)){
        return false;
    }
    std::string token;
     while(std::cin >> token){
        Number right;
                if(token == "+"){
                   if(!ReadNumber(right)){
                    return false;
                   }else{
                    current_number += right;
                 }
             } else if(token == "-"){
                Number right;
                if(!ReadNumber(right)){
                     return false;
                 }else{
                    current_number -= right;
                    }
             } else if(token == "*"){
                if(!ReadNumber(right)){
                     return false;
                 }else{
                    current_number *= right;
                 }
             } else if(token == "/"){
                if(!ReadNumber(right)){
                     return false;
                 }else{
                    current_number /= right;
                 }
             } else if(token == "**"){
                if(!ReadNumber(right)){
                     return false;
                 }else{
                    current_number = std::pow(current_number, right);
                 }
            }else if(token == ":"){
                if(!ReadNumber(right)){
                     return false;
                 }else{
                    current_number = right;
                 }
            }else if(token == "c"){
               current_number = 0;
             }else if(token == "="){
            std::cout << current_number << std::endl;
            }else if(token ==  "q"){
                    return true;
             }else if(token == "s"){
                saved_number = current_number;
                number_is_saved = true;
             }else if(token == "l"){
                if(!number_is_saved){
                    std::cerr << "Error: Memory is empty" << std::endl;
                     return false;
                }
                current_number = saved_number;
             }else{
                std::cerr << "Error: Unknown token " << token << std::endl;
                return false;
             }
         }
         return true;
}
