//
// Created by Lynkan on 2021-06-03.
//

#include "battleships.h"
#include <iostream>
#include <array>
using namespace std;

const int playAreaSize = 8;
using playAreaArrayRef = array<array<array<int,playAreaSize>, playAreaSize>, 2>;

void DoBattleshipsLoop();

// Playing Area Setup Declarations
playAreaArrayRef InitializeGameplayArea();
bool ValidateShipPlacement(array<char, 2>, playAreaArrayRef);
playAreaArrayRef PlaceShip(string position, playAreaArrayRef);


// Gameplay Logic Declarations
void DoBattleshipsTurn(string);
bool ValidateInput(string);
array<char, 2> SplitInput(string);
array<int,2> ConvertInputSplitToValues(array<char,2>);

playAreaArrayRef UpdateGameplayArea(playAreaArrayRef);
void PrintGameplayArea(playAreaArrayRef);


void PrintGameplayArea(playAreaArrayRef currentPlayArea){
    cout << "Printing game field" << endl;
}


bool ValidateShipPlacement(array<char, 2> splitPos, playAreaArrayRef currentPlayArea){
    array<int,2> splitPosValues = ConvertInputSplitToValues(splitPos);

    for(const auto& column : currentPlayArea)
        for(const auto& row : column)
            if(splitPosValues[0] == row.size()-1){
                cout << "You cannot enter a position on the bottom line! Try again" << endl;
                return 0;

            }
            else{
                for(const auto& cell : row)
                    if(cell != ' '){
                        cout << "The selected cell is not empty. Try again" << endl;
                        return 0;
                    }
            }

    return 1;
}

playAreaArrayRef PlaceShip(array<char, 2> position, playAreaArrayRef currentPlayArea){
    playAreaArrayRef playArea = currentPlayArea;

    array<int,2> positionValues = ConvertInputSplitToValues(position);





    return playArea;
}

array<int,2> ConvertInputSplitToValues(array<char,2> splitInput){

    array<int, 2> inputValues;

    switch (splitInput[0]) {
        case 'A':
            inputValues[0] = 1;
        case 'B':
            inputValues[0] = 2;
        case 'C':
            inputValues[0] = 3;
        case 'D':
            inputValues[0] = 4;
        case 'E':
            inputValues[0] = 5;
        case 'F':
            inputValues[0] = 6;
        case 'G':
            inputValues[0] = 7;
        case 'H':
            inputValues[0] = 8;
        default:
            inputValues[0] = 1;
            break;
    }
    switch (splitInput[1]) {
        case 1:
            inputValues[1] = 1;
        case 2:
            inputValues[1] = 2;
        case 3:
            inputValues[1] = 3;
        case 4:
            inputValues[1] = 4;
        case 5:
            inputValues[1] = 5;
        case 6:
            inputValues[1] = 6;
        case 7:
            inputValues[1] = 7;
        case 8:
            inputValues[1] = 8;
        default:
            break;
    }

    return inputValues;
}


playAreaArrayRef InitializeGameplayArea(){
    playAreaArrayRef playArea;
    bool placementDone = 0;

    PrintGameplayArea(playArea);

    cout << "Placement phase, please enter a coordinate (like A1) where you want to place your ships:" << endl;
    // TODO: Allow player to enter positions for their ships

    int shipsLeft = 2;

    while(!placementDone){
        if(shipsLeft <= 0)
            break;

        cout << "Ships left to place: " << shipsLeft << endl;

        string input = "";
        cin >> input;

        if(ValidateInput(input)){
            array<char,2> splitInput = SplitInput(input);
            if(!ValidateShipPlacement(splitInput, playArea)){
                // Do Nothing
            }
            else{
                playArea = PlaceShip(splitInput, playArea);
                shipsLeft--;
            }
        }
    }

    // TODO: Place AI's ships

    return playArea;
}



void DoBattleshipsTurn(string input){
    array<char, 2> splitInput = SplitInput(input);

    // TODO: Depending on PlayerTurn or AI Turn:
    // PlayerTurn: Attack the inputted coordinate

    // AI Turn: Attack a randomly generated coordinate
        // TODO: Improve AI to detect hit areas and prioritize hitting areas around there
            // TODO: Give AI better valuations based on consecutive hits to improve likelyhood of it continuing to attack a ship

}

array<char, 2> SplitInput(string input){
    // TODO: Split input into a 2 index array, representing Column and Row to attack
    array<char, 2> splitInput;

    splitInput[0] = input[0];
    splitInput[1] = input[1];

    return splitInput;
}

bool ValidateInput(string input){
    // TODO: Check if input is 2 characters long, if the first entry is a character and the second entry is a number between 1-9

    if(input.length() <= 1 || input.length() >= 3)
    {
        cout << "Input cannot be less or more than 1 character and 1 number (like A1)" << endl;
        return 0;
    }
    if(!isalpha(input[0]))
    {
        cout << "First character has to be a letter between A-H" << endl;
        return 0;
    }
    if(!isdigit(input[1]) || (int)input[1] <= 0 || (int)input[1] > playAreaSize)
    {
        cout << input[1] << endl;
        cout << (int)input[1] << endl;
        cout << "Second character has to be a a number between 1-8" << endl;
        return 0;
    }

    return 1;
}


void DoBattleshipsLoop(){
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
                DoBattleshipsTurn(input);
        }
    }
}

void RunBattleships(){
    std::cout << "Battleships!" << std::endl;
    DoBattleshipsLoop();
}