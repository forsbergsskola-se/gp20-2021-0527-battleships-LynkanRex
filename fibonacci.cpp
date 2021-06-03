//
// Created by Lynkan on 2021-06-01.
//

#include <iostream>
#include <sstream>
#include <chrono>
#include "fibonacci.h"
using namespace std;
using namespace chrono;
using namespace std::literals::chrono_literals;

void DoLoop();
bool InputIsNumber(string);
void InitializeRecursiveFibonacci(int);
void InitializeIterativeFibonacci(int);

void IterativeFibonacci(int, int, long long);
void RecursiveFibonacci(int, int, long long);
void PrintTimeTaken(string, long long);

long long CalculateFibonacciNumber(int);


long long CalculateFibonacciNumber(int fibTerm){
    auto start = chrono::high_resolution_clock::now();

    int t1 = 0, t2 = 1, nextTerm = 0;

    for (int i = 0; i < fibTerm; ++i) {
        if(i == 1){
            return t1;
        }
        if(i == 2){
            return t2;
        }
        nextTerm = t1 + t2;

        t1 = t2;
        t2 = nextTerm;
    }

    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    long long microSeconds =  std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

    return microSeconds;
}

void RecursiveFibonacci(int requestedIterations, int currentFibCount, long long timer){

    timer += CalculateFibonacciNumber(currentFibCount);

    if(requestedIterations == currentFibCount)
        PrintTimeTaken("Recursive", timer);
    else
        RecursiveFibonacci(requestedIterations, currentFibCount+1, timer);
}

void PrintTimeTaken(string type, long long timeTaken){
    cout << type << " finished in: " << timeTaken << " microseconds" << endl;
}

void IterativeFibonacci(int timesLeft, int currentFib, long long timer){
    auto start = chrono::high_resolution_clock::now();
    int t1 = 0, t2 = 1, nextTerm = 0;

    for (int i = 0; i < timesLeft; ++i) {
        if(i == 1){
            currentFib = t1;

        }
        if(i == 2){
            currentFib = t2;

        }
        nextTerm = t1 + t2;

        t1 = t2;
        t2 = nextTerm;
    }

    auto elapsed = std::chrono::high_resolution_clock::now() - start;

    long long timeTaken =  std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

    PrintTimeTaken("Iterative", timeTaken);
}

void InitializeIterativeFibonacci(int num){
    IterativeFibonacci(num, 0, 0);
}

void InitializeRecursiveFibonacci(int num){
    RecursiveFibonacci(num, 0, 0);
}

bool InputIsNumber(string input){
    if(input.empty()){
        cout << "Input was empty, please enter something" << endl;
        return 0;
    }
    else{
        for (int i = 0; i < input.length(); ++i) {
            if(!isdigit(input[i])){
                if(input[i] == '-')
                    continue;
                cout << "Input given contained something that was not a digit at " << input[i] << endl;
                return 0;
            }
        }
        return 1;
    }
}

void DoLoop(){
 while(true){
     string input = "";
     int num = 0;

     cout << "Fibonacci numbers calculation time in Recursive vs Iterative mode, please enter how many terms you would like the calculation to take" << endl;
     cin >> input;

     if(input == "exit")
         break;

     if(InputIsNumber(input)){
         stringstream ss;

         ss << input;
         ss >> num;

         InitializeRecursiveFibonacci(num);
         InitializeIterativeFibonacci(num);
        }
     }
}


void RunFibonacci(){
    DoLoop();
}