//
// Created by Lynkan on 2021-06-03.
//

#include "battleships.h"
#include <iostream>
#include <array>
using namespace std;

void DoLoop();
array<array<int, 10>, 10> InitializeGameplayArea();
array<array<int, 10>, 10> UpdateGameplayArea(array<array<int, 10>, 10>);

void DoTurn(string);
bool ValidateInput(string);
array<char, 2> SplitInput(string);



array<array<int, 10>, 10> InitializeGameplayArea(array<array<int, 10>, 10> currentPlayArea){
    array<array<int, 10>, 10> playArea;


    return playArea;
}



void DoTurn(string input){
    array<char, 2> splitInput = SplitInput(input);


}

array<char, 2> SplitInput(string input){


}

bool ValidateInput(string input){
    if(input == "")
        return 0;

    return 1;
}


void DoLoop(){
    array<array<int, 10>, 10> playArea = InitializeGameplayArea();

    while(true){
        string input = "";
        cin >> input;

        if(input == "exit"){
            cout << "Thank you for playing!" << endl;
            break;
        }
        else{
            if(ValidateInput(input))
                DoTurn(input);
        }
    }
}

void RunBattleships(){
    std::cout << "Battleships!" << std::endl;
    DoLoop();
}