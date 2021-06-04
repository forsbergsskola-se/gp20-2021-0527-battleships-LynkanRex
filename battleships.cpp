//
// Created by Lynkan on 2021-06-03.
//

#include "battleships.h"
#include <iostream>
#include <array>
using namespace std;

const int playAreaSize = 9;
using playAreaArrayRef = array<array<array<int,playAreaSize>, playAreaSize>, 2>;

void DoLoop();

// Playing Area Setup Declarations
playAreaArrayRef InitializeGameplayArea();
playAreaArrayRef UpdateGameplayArea(playAreaArrayRef);
void PrintGameplayArea(playAreaArrayRef);

playAreaArrayRef PlaceShip(string position, playAreaArrayRef);

// Gameplay Logic Declarations
void DoTurn(string);
bool ValidateInput(string);
array<char, 2> SplitInput(string);




playAreaArrayRef PlaceShip(string position, playAreaArrayRef currentPlayArea){
    playAreaArrayRef playArea = currentPlayArea;
    array<char, 2> splitInput;

    splitInput = SplitInput(position);

    switch (splitInput[0]) {
        default:
            break;
    }
    switch (splitInput[1]) {
        default:
            break;
    }


    return playArea;
}

playAreaArrayRef InitializeGameplayArea(playAreaArrayRef currentPlayArea){
    playAreaArrayRef playArea = currentPlayArea;
    bool placementDone = 0;

    // TODO: Allow player to enter positions for their ships

    int shipsLeft = 2;

    while(!placementDone){
        if(shipsLeft <= 0)
            break;

        string input = "";
        cin >> input;

        if(ValidateInput(input))


        playArea = PlaceShip(input, playArea);


    }

    // TODO: Place AI's ships

    return playArea;
}



void DoTurn(string input){
    array<char, 2> splitInput = SplitInput(input);

    // TODO: Depending on PlayerTurn or AI Turn:
    // PlayerTurn: Attack the inputted coordinate

    // AI Turn: Attack a randomly generated coordinate
        // TODO: Improve AI to detect hit areas and prioritize hitting areas around there
            // TODO: Give AI better valuations based on consecutive hits to improve likelyhood of it continuing to attack a ship

}

array<char, 2> SplitInput(string input){
    // TODO: Split input into a 2 index array, representing Column and Row to attack

}

bool ValidateInput(string input){
    // TODO: Check if input is 2 characters long, if the first entry is a character and the second entry is a number between 1-9

    if(input.length() <= 1 || input.length() >= 3)
        return 0;
    if(input[0] != 'n')
        return 0;
    if(input[1] != '0')
        return 0;

    return 1;
}


void DoLoop(){
    playAreaArrayRef playArea = InitializeGameplayArea();

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