//
// Created by Lynkan on 2021-06-03.
//

#include "random.h"
#include <array>
#include <iostream>
#include <ctime>
using namespace std;
using std::array;


void DoRandomLoop(int times){
    array<int, 20> numbers = {0,0,0,0,0,
                              0,0,0,0,0,
                              0,0,0,0,0,
                              0,0,0,0,0};

    srand(time(0));

    for (int i = 0; i < times; ++i) {
        int randomNum = (rand() % 20) +1;
        cout << randomNum << endl;
        numbers[randomNum] += 1;
    }

    cout << "Distribution of rolled numbers;" << endl;
    for (const auto& number : numbers) {
        cout << number << endl;
    }

}


void RunRandom(){
    DoRandomLoop(20);
}