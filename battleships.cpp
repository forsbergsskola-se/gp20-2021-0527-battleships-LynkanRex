//
// Created by Lynkan on 2021-06-03.
//

#include "battleships.h"
#include <iostream>
using namespace std;

void DoLoop();
void InitializeGameplayArea();
void UpdateGameplayArea();

void DoTurn();

bool ValidateInput(string input);
void SplitInput(string input);




void DoLoop(){
    while(true){
        string input = "";
        cin >> input;

        if(input == "exit"){
            cout << "Thank you for playing!" << endl;
            break;
        }
    }
}

void RunBattleships(){
    std::cout << "Battleships!" << std::endl;
    DoLoop();
}