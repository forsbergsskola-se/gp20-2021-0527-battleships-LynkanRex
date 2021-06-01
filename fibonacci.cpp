//
// Created by Lynkan on 2021-06-01.
//

#include <iostream>
#include <sstream>
#include "fibonacci.h"
using namespace std;

void DoLoop();
bool ValidateInput(string);
bool InputIsNumber(string);
void InitializeRecursiveFibonacci(int);
void InitializeIterativeFibonacci(int);

void RecursiveFibonacci(int, int, float);
void RecursiveFibonacciTimer(float);

void IterativeFibonacci(int, int, float);


void RecursiveFibonacci(int timesLeft, int currentFib, float timer){

    if(timesLeft <= 0)
        RecursiveFibonacciTimer(timer);
    else
        RecursiveFibonacci(timesLeft-1, currentFib, timer);
}

void RecursiveFibonacciTimer(float timer){

}

void IterativeFibonacci(int timesLeft, int currentFib, float timer){

    for (int i = 0; i < timesLeft; ++i) {

    }
}

void InitializeIterativeFibonacci(int num){
    IterativeFibonacci(num, 0, 0.0f);
}

void InitializeRecursiveFibonacci(int num){
    RecursiveFibonacci(num, 0, 0.0f);
}

void DoLoop(){
 while(true){
     string input = "";
     int num = 0;

     if(input == "exit")
         break;

     if(ValidateInput(input))
         if(InputIsNumber(input)){
             stringstream ss;

             ss << input;
             ss >> num;

             InitializeRecursiveFibonacci(num);
             InitializeIterativeFibonacci(num);
         };
     }
}


void RunFibonacci(){
    DoLoop();
}