//
// Created by Lynkan on 2021-06-03.
//

#include "battleships.h"
#include <iostream>
#include <array>
#include <ctime>
using namespace std;

using playAreaArrayRef = int[8][8];
using playAreaArrayRefAI = int[8][8];

const int playAreaSize = 8;
const int SmallCruiser1 = 1;
const int SmallCruiser2 = 2;
const int Corsair = 3;
const int Battleship = 4;
const int Carrier = 5;


class Cell{
public:
    int value = 32;
};

class ShipType{
public:
    int size;
    int numericalSymbol;
    string nameSymbol;
};

class Ship{
public :
    string name;
    ShipType shipType;
};

void DoBattleshipsLoop();
Ship* SetupShips(Ship[5]);

// Playing Area Setup Declarations
void InitializeGameplayAreaForPlayer(int(*a)[8][8], Ship[5]);
void InitializeGameplayAreaForAI();
bool ValidateShipPlacement(array<char, 3>, playAreaArrayRef);
void PlaceShip(string position, int(*a)[8][8]);

// Gameplay Logic Declarations
void DoBattleshipsTurn(string);
void AttackCell(int(*a)[8][8]);

// Input validations
bool ValidateInput(string);
array<char, 3> SplitInput(string);
array<int,2> ConvertInputSplitToValues(array<char,2>);
array<int,3> ConvertInputSplitToValues(array<char,3>);

// Printing game state logic
void UpdateGameplayArea(int[8][8],int[8][8]);
void PrintGameplayArea(int (*a)[8][8], int (*b)[8][8]);
void PlacementPrintGameplayArea(int [8][8], Ship[5]);

void PlacementPrintGameplayArea(Cell (*a)[8], Ship (playerShips)[5]){
    for (int i = 0; i < 8; ++i) {
        // TODO: Print ABCDEFGH
        for (int j = 0; j < 8; ++j) {
            //TODO: Print 12345678
            if(a[i][j].value == 32){
                cout << " [" << "  " << "] ";
            }
            else if(a[i][j].value == SmallCruiser1)
                cout << " [" << playerShips[0].shipType.nameSymbol << "] ";
            else if(a[i][j].value == SmallCruiser2)
                cout << " [" << playerShips[1].shipType.nameSymbol << "] ";
            else if(a[i][j].value == Corsair)
                cout << " [" << playerShips[2].shipType.nameSymbol << "] ";
            else if(a[i][j].value == Battleship)
                cout << " [" << playerShips[3].shipType.nameSymbol << "] ";
            else if(a[i][j].value == Carrier)
                cout << " [" << playerShips[4].shipType.nameSymbol << "] ";
            else{
                cout << " [" << 'x' << "] ";
            }
        }
        cout << endl;
    }
}



void PrintGameplayArea(Cell (*a)[8], Cell (*b)[8], Ship (playerShip)[5], Ship(AIShips)[5]){
    cout << "Enemy's Playfield;" << endl;

    for (int i = 0; i < 8; ++i) {
        // TODO: Print ABCDEFGH
        for (int j = 0; j < 8; ++j) {
            //TODO: Print 12345678
            if(b[i][j].value == 32){
                cout << " [" << "  " << "] ";
            }
            else if(b[i][j].value == SmallCruiser1)
                cout << " [" << AIShips[0].shipType.nameSymbol << "] ";
            else if(b[i][j].value == SmallCruiser2)
                cout << " [" << AIShips[1].shipType.nameSymbol << "] ";
            else if(b[i][j].value == Corsair)
                cout << " [" << AIShips[2].shipType.nameSymbol << "] ";
            else if(b[i][j].value == Battleship)
                cout << " [" << AIShips[3].shipType.nameSymbol << "] ";
            else if(b[i][j].value == Carrier)
                cout << " [" << AIShips[4].shipType.nameSymbol << "] ";
            else{
                cout << " [" << "x " << "] ";
            }
        }
        cout << endl;
    }
    cout << "------------------------" << endl;
    cout << "Your Playfield;" << endl;
    for (int i = 0; i < 8; ++i) {
        // TODO: Print ABCDEFGH
        for (int j = 0; j < 8; ++j) {
            //TODO: Print 12345678
            if(a[i][j].value == 32){
                cout << " [" << "  " << "] ";
            }
            else if(a[i][j].value == SmallCruiser1)
                cout << " [" << playerShip[0].shipType.nameSymbol << "] ";
            else if(a[i][j].value == SmallCruiser2)
                cout << " [" << playerShip[1].shipType.nameSymbol << "] ";
            else if(a[i][j].value == Corsair)
                cout << " [" << playerShip[2].shipType.nameSymbol << "] ";
            else if(a[i][j].value == Battleship)
                cout << " [" << playerShip[3].shipType.nameSymbol << "] ";
            else if(a[i][j].value == Carrier)
                cout << " [" << playerShip[4].shipType.nameSymbol << "] ";
            else{
                cout << " [" << "x " << "] ";
            }
        }
        cout << endl;
    }

}


bool ValidateShipPlacement(array<char, 3> splitPos, Cell (*a)[8], Ship shipToPlace, bool playerTurn){
    array<int,3> splitPosValues = ConvertInputSplitToValues(splitPos);

    if(splitPosValues[2] == 0){
        if(splitPosValues[0]+shipToPlace.shipType.size > playAreaSize){
            if(playerTurn)
                cout << "Placing a ship here, with this rotation would overflow downwards" << endl;
            return 0;
        }


        for (int i = 0; i < playAreaSize; ++i) {
            for (int j = 0; j < playAreaSize; ++j) {
                if(i == splitPosValues[0] && j == splitPosValues[1]){
                    if(a[splitPosValues[0]][splitPosValues[1]].value != 32){
                        if(playerTurn)
                            cout << "The selected cell is not empty. Try again" << endl;
                        return 0;
                    }
                    else{
                        for (int k = 1; k < shipToPlace.shipType.size; ++k) {
                            if(a[splitPosValues[0]+k][splitPosValues[1]].value != 32){
                                if(playerTurn)
                                    cout << "Non-empty cells downards after your selection detected. Try something else" << endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    else if(splitPosValues[2] == 1){
        if(splitPosValues[1]+shipToPlace.shipType.size > playAreaSize){
            if(playerTurn)
                cout << "Placing a ship here, with this rotation would overflow to the right" << endl;
            return 0;
        }


        for (int i = 0; i < playAreaSize; ++i) {
            for (int j = 0; j < playAreaSize; ++j) {
                if(i == splitPosValues[0] && j == splitPosValues[1]){
                    if(a[splitPosValues[0]][splitPosValues[1]].value != 32){
                        if(playerTurn)
                            cout << "The selected cell is not empty. Try again" << endl;
                        return 0;
                    }
                    else{
                        for (int k = 1; k < shipToPlace.shipType.size; ++k) {
                            if(a[splitPosValues[0]][splitPosValues[1]+k].value != 32){
                                if(playerTurn)
                                    cout << "Non-empty cells to the right of your selection detected. Try something else" << endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    return 1;
}

void PlaceShip(array<char, 3> position, Cell (*a)[8], Ship shipToPlace){
    array<int,3> positionValues = ConvertInputSplitToValues(position);
    bool foundTargetCell = false;

    if(positionValues[2] == 0){
        for (int i = 0; i <8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if(i == positionValues[0] && j == positionValues[1]){
                    a[positionValues[0]][positionValues[1]].value = shipToPlace.shipType.numericalSymbol;
                    for (int k = 1; k < shipToPlace.shipType.size; ++k) {
                        a[positionValues[0]+k][positionValues[1]].value = shipToPlace.shipType.numericalSymbol;
                    }
                    foundTargetCell = true;
                    break;
                }
            }
            if(foundTargetCell) break;
        }
    }
    else if(positionValues[2] == 1){
        for (int i = 0; i <8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if(i == positionValues[0] && j == positionValues[1]){
                    a[positionValues[0]][positionValues[1]].value = shipToPlace.shipType.numericalSymbol;
                    for (int k = 1; k < shipToPlace.shipType.size; ++k) {
                        a[positionValues[0]][positionValues[1]+k].value = shipToPlace.shipType.numericalSymbol;
                    }
                    foundTargetCell = true;
                    break;
                }
            }
            if(foundTargetCell) break;
        }
    }

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
            inputValues[0] = 0;
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

array<int,3> ConvertInputSplitToValues(array<char,3> splitInput){

    array<int, 3> inputValues;

    splitInput[0] = tolower(splitInput[0]);
    splitInput[2] = tolower(splitInput[2]);

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
            inputValues[0] = 0;
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

    switch (splitInput[2]) {
        case 'd':
            inputValues[2] = 0;
            break;
        case 'r':
            inputValues[2] = 1;
            break;
        default:
            inputValues[2] = 10;
            break;
    }

    return inputValues;
}


string RandomizedAIPlacement(){
    string newString = "000";

    newString[0] = (rand() % 8) +1;
    newString[1] = (rand() % 8) +1;
    newString[2] = (int)(rand() % 2);


    switch (newString[0]) {
        case 0:
            newString[0] = 'A';
            break;
        case 1:
            newString[0] = 'B';
            break;
        case 2:
            newString[0] = 'C';
            break;
        case 3:
            newString[0] = 'D';
            break;
        case 4:
            newString[0] = 'E';
            break;
        case 5:
            newString[0] = 'F';
            break;
        case 6:
            newString[0] = 'G';
            break;
        case 7:
            newString[0] = 'H';
            break;
        default:
            newString[0] = 'A';
            break;
    }
    switch (newString[1]) {
        case 0:
            newString[1] = '1';
            break;
        case 1:
            newString[1] = '2';
            break;
        case 2:
            newString[1] = '3';
            break;
        case 3:
            newString[1] = '4';
            break;
        case 4:
            newString[1] = '5';
            break;
        case 5:
            newString[1] = '6';
            break;
        case 6:
            newString[1] = '7';
            break;
        case 7:
            newString[1] = '8';
            break;
        default:
            newString[1] = '1';
            break;
    }
    switch (newString[2]) {
        case 0:
            newString[2] = 'D';
            break;
        case 1:
            newString[2] = 'R';
            break;
        default:
            newString[2] = 'D';
            break;
    }

    return newString;
}

void InitializeGameplayAreaForAI(Cell (*b)[8][8], Ship (aiShips)[5]){
    bool placementDone = 0;
    cout << "Enemy is placing their ships..." << endl;

    int placedShips = 0;
    int shipsToPlace = 5;

    while(!placementDone){
        if(placedShips >= shipsToPlace)
            break;

        string AIInput = RandomizedAIPlacement();

        if(ValidateInput(AIInput)){
            array<char, 3> AIPlayerPlacementInput = SplitInput(AIInput);
            if(ValidateShipPlacement(AIPlayerPlacementInput, *b, aiShips[placedShips], false)){
                PlaceShip(AIPlayerPlacementInput, *b, aiShips[placedShips]);
                placedShips++;
            }
        }
    }
    // TODO: Place AI's ships
}


void InitializeGameplayAreaForPlayer(Cell (*a)[8][8], Ship (playerShips)[5]){
    bool placementDone = 0;
    cout << "Placement phase, please enter a coordinate and rotation (like A1D, F4R) where you want to place your ships:" << endl;

    int placedShips = 0;
    int shipsToPlace = 5;

    while(!placementDone){

        PlacementPrintGameplayArea(*a,playerShips);
        if(placedShips >= shipsToPlace)
            break;

        cout << "Ships left to place: " << shipsToPlace-placedShips << endl;

        string input = "";
        cin >> input;

        if(ValidateInput(input)){
            array<char,3> splitInput = SplitInput(input);
            if(ValidateShipPlacement(splitInput, *a, playerShips[placedShips], true))
            {
                PlaceShip(splitInput, *a, playerShips[placedShips]);
                placedShips++;
            }
        }
    }
}



void DoBattleshipsTurn(string input){
    array<char, 3> splitInput = SplitInput(input);

    // TODO: Depending on PlayerTurn or AI Turn:
    // PlayerTurn: Attack the inputted coordinate

    // AI Turn: Attack a randomly generated coordinate
        // TODO: Improve AI to detect hit areas and prioritize hitting areas around there
            // TODO: Give AI better valuations based on consecutive hits to improve likelyhood of it continuing to attack a ship

}

array<char, 3> SplitInput(string input){
    array<char, 3> splitInput;

    splitInput[0] = input[0];
    splitInput[1] = input[1];
    splitInput[2] = input[2];

    return splitInput;
}


bool ValidateInput(string input){

    if(input.length() <= 1 || input.length() >= 4)
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
    if(input[2] != 'D' && input[2] != 'R')
    {
        cout << "Last character has to be either D or R for rotation" << endl;
        return 0;
    }
    if((int)input[1]-48 <= 0 || (int)input[1]-48 > playAreaSize){
        cout << "Second number must be between 1 and 8" << endl;

    }

    return 1;
}

Ship* SetupShips(Ship ships[5]){

    ships[0].name = "Small Cruiser1";
    ships[1].name = "Small Cruiser2";
    ships[2].name = "Corsair";
    ships[3].name = "Battleship";
    ships[4].name = "Cruiser";

    ships[0].shipType.nameSymbol = "S1";
    ships[1].shipType.nameSymbol = "S2";
    ships[2].shipType.nameSymbol = "C1";
    ships[3].shipType.nameSymbol = "B ";
    ships[4].shipType.nameSymbol = "C2";

    ships[0].shipType.size = 2;
    ships[1].shipType.size = 2;
    ships[2].shipType.size = 3;
    ships[3].shipType.size = 4;
    ships[4].shipType.size = 5;

    ships[0].shipType.numericalSymbol = SmallCruiser1;
    ships[1].shipType.numericalSymbol = SmallCruiser2;
    ships[2].shipType.numericalSymbol = Corsair;
    ships[3].shipType.numericalSymbol = Battleship;
    ships[4].shipType.numericalSymbol = Carrier;

    return ships;
}


void DoBattleshipsLoop(){

    Cell playerAreaPlayer[playAreaSize][playAreaSize];
    Cell playerAreaAI[playAreaSize][playAreaSize];

    Ship playerShips[5];
    Ship AIShips[5];

    SetupShips(playerShips);
    SetupShips(AIShips);

    InitializeGameplayAreaForPlayer(&playerAreaPlayer, playerShips);
    InitializeGameplayAreaForAI(&playerAreaAI, AIShips);

    while(true){
        PrintGameplayArea(playerAreaPlayer, playerAreaAI, playerShips, AIShips);

        // TODO: Toggle back and forth between player and AI turn

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
    srand(time(NULL));
    std::cout << "Battleships!" << std::endl;
    DoBattleshipsLoop();
}


