//
// Created by Lynkan on 2021-06-03.
//

#include "battleships.h"
#include <iostream>
#include <array>
using namespace std;

const int playAreaSize = 8;
using playAreaArrayRef = int[8][8];
using playAreaArrayRefAI = int[8][8];

void DoBattleshipsLoop();

// Playing Area Setup Declarations
void InitializeGameplayAreaForPlayer(int(*a)[8][8]);
void InitializeGameplayAreaForAI();
bool ValidateShipPlacement(array<char, 2>, playAreaArrayRef);
void PlaceShip(string position, int(*a)[8][8]);


// Gameplay Logic Declarations
void DoBattleshipsTurn(string);
bool ValidateInput(string);
array<char, 2> SplitInput(string);
array<int,2> ConvertInputSplitToValues(array<char,2>);

void UpdateGameplayArea(int[8][8],int[8][8]);

void PrintGameplayArea(int (*a)[8][8], int (*b)[8][8]);
void PlacementPrintGameplayArea(int [8][8]);

void PlacementPrintGameplayArea(int (*a)[8]){
    for (int i = 0; i < 8; ++i) {
        // TODO: Print ABCDEFGH
        for (int j = 0; j < 8; ++j) {
            if(a[i][j] == 32){
                //TODO: Print 12345678
                cout << " [" << ' ' << "] ";
            }
            else if(a[i][j] == 66)
                cout << " [" << 'B' << "] ";
            else{
                cout << " [" << 'x' << "] ";
            }
        }
        cout << endl;
    }
}



void PrintGameplayArea(int (*a)[8], int (*b)[8]){

    for (int i = 0; i < 8; ++i) {
        // TODO: Print ABCDEFGH
        for (int j = 0; j < 8; ++j) {
           if(a[i][j] == 32){
               //TODO: Print 12345678
               cout << " [" << ' ' << "] ";
           }
           else if(a[i][j] == 66)
               cout << " [" << 'B' << "] ";
           else{
               cout << " [" << 'x' << "] ";
           }
        }
        cout << endl;
    }
    cout << "------------------------" << endl;
    for (int i = 0; i < 8; ++i) {
        // TODO: Print ABCDEFGH
        for (int j = 0; j < 8; ++j) {
            if(b[i][j] == 32){
                //TODO: Print 12345678
                cout << " [" << ' ' << "] ";
            }
            else if(b[i][j] == 66)
                cout << " [" << 'B' << "] ";
            else{
                cout << " [" << 'x' << "] ";
            }
        }
        cout << endl;
    }

}


bool ValidateShipPlacement(array<char, 2> splitPos, int (*a)[8]){
    array<int,2> splitPosValues = ConvertInputSplitToValues(splitPos);

    if(splitPosValues[0] >= playAreaSize-1){
        cout << "You cannot enter a position on the bottom line! Try again" << endl;
        return 0;
    }


    for (int i = 0; i <8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if(i == splitPosValues[0] && j == splitPosValues[1]){
                if(a[splitPosValues[0]][splitPosValues[1]] != 32){
                    cout << "The selected cell " << i<<j << " is not empty. Try again" << endl;
                    return 0;
                }
                else if(a[splitPosValues[0]+1][splitPosValues[1]] != 32){
                    cout << "The cell after your selection " << i<<j << " is not empty. Try something else" << endl;
                    return 0;
                }
            }
        }
    }

    return 1;
}

void PlaceShip(array<char, 2> position, int (*a)[8]){
    array<int,2> positionValues = ConvertInputSplitToValues(position);
    bool foundTargetCell = false;

    for (int i = 0; i <8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if(i == positionValues[0] && j == positionValues[1]){
                a[positionValues[0]][positionValues[1]] = 66;
                a[positionValues[0]+1][positionValues[1]] = 66;
                foundTargetCell = true;
                break;
            }
        }
        if(foundTargetCell) break;
    }
    // TODO: Update contents of the specified cells and rows with something other than ' '

}

array<int,2> ConvertInputSplitToValues(array<char,2> splitInput){

    array<int, 2> inputValues;

    splitInput[0] = tolower(splitInput[0]);

    switch (splitInput[0]) {
        case 'a':
            inputValues[0] = 0;
            break;
        case 'b':
            inputValues[0] = 1;
            break;
        case 'c':
            inputValues[0] = 2;
            break;
        case 'd':
            inputValues[0] = 3;
            break;
        case 'e':
            inputValues[0] = 4;
            break;
        case 'f':
            inputValues[0] = 5;
            break;
        case 'g':
            inputValues[0] = 6;
            break;
        case 'h':
            inputValues[0] = 7;
            break;
        default:
            inputValues[1] = 0;
            break;
    }

    int numberizedValue = splitInput[1]-48;


    switch (numberizedValue) {
        case 1:
            inputValues[1] = 0;
            break;
        case 2:
            inputValues[1] = 1;
            break;
        case 3:
            inputValues[1] = 2;
            break;
        case 4:
            inputValues[1] = 3;
            break;
        case 5:
            inputValues[1] = 4;
            break;
        case 6:
            inputValues[1] = 5;
            break;
        case 7:
            inputValues[1] = 6;
            break;
        case 8:
            inputValues[1] = 7;
            break;
        default:
            inputValues[1] = 0;
            break;
    }

    return inputValues;
}


void InitializeGameplayAreaForAI(){
    playAreaArrayRefAI *playAreaAI;

    // TODO: Place AI's ships

}


void InitializeGameplayAreaForPlayer(int (*a)[8][8]){
    cout << "Placement phase, please enter a coordinate (like A1) where you want to place your ships:" << endl;

    bool placementDone = 0;
    int shipsLeft = 2;

    while(!placementDone){

        PlacementPrintGameplayArea(*a);
        if(shipsLeft <= 0)
            break;

        cout << "Ships left to place: " << shipsLeft << endl;

        string input = "";
        cin >> input;

        // TODO: Add an If-tree for the AI randomized placements

        if(ValidateInput(input)){
            array<char,2> splitInput = SplitInput(input);
            if(ValidateShipPlacement(splitInput, *a))
            {
                PlaceShip(splitInput, *a);
                shipsLeft--;
            }
        }
    }

    // TODO: Place AI's ships
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
    array<char, 2> splitInput;

    splitInput[0] = input[0];
    splitInput[1] = input[1];

    return splitInput;
}

bool ValidateInput(string input){

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
    if(!isdigit(input[1]))
    {
        cout << input[1] << endl;
        cout << (int)input[1] << endl;
        cout << "Second character has to be a a number" << endl;
        return 0;
    }
    if((int)input[1]-48 <= 0 || (int)input[1]-48 > playAreaSize){
        cout << "Second number must be between 1 and 8" << endl;

    }

    return 1;
}


void DoBattleshipsLoop(){
    int playerAreaPlayer[8][8] = {{32,32,32,32,32,32,32,32},
                                  {32,32,32,32,32,32,32,32},
                                  {32,32,32,32,32,32,32,32},
                                  {32,32,32,32,32,32,32,32},
                                  {32,32,32,32,32,32,32,32},
                                  {32,32,32,32,32,32,32,32},
                                  {32,32,32,32,32,32,32,32},
                                  {32,32,32,32,32,32,32,32}
    };
    int playAreaAI[8][8] = {{32,32,32,32,32,32,32,32},
                            {32,32,32,32,32,32,32,32},
                            {32,32,32,32,32,32,32,32},
                            {32,32,32,32,32,32,32,32},
                            {32,32,32,32,32,32,32,32},
                            {32,32,32,32,32,32,32,32},
                            {32,32,32,32,32,32,32,32},
                            {32,32,32,32,32,32,32,32}
    };

    InitializeGameplayAreaForPlayer(&playerAreaPlayer);

    while(true){
        PrintGameplayArea(playerAreaPlayer, playAreaAI);

        string input = "";
        cin >> input;

        if(input == "exit"){
            cout << "Game over! Thank you for playing!" << endl;
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