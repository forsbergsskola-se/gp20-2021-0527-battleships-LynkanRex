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
    int numberRef = 0;

    srand(time(NULL));

    for (int i = 0; i < times; ++i) {
        int randomNum = (rand() % 20);
        numbers[randomNum] += 1;
    }

    cout << "Distribution of rolled numbers;" << endl;
    for (const auto& number : numbers) {
        numberRef++;
        cout << numberRef <<" times rolled: " << number << endl;
    }

}


void RunRandom(){
    DoRandomLoop(100);
}