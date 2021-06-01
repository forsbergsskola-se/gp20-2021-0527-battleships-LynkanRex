//
// Created by Lynkan on 2021-06-01.
//

#include <iostream>
#include <sstream>
#include "programlist.h"
using namespace std;

int main(){
    int programRunning = 1;

    while(programRunning){
        string choice = "";
        int num;

        cout << "Enter a number to choose a program, or enter 'exit' to quit;" << endl;
        cin >> choice;

        stringstream ss;
        ss << choice;
        ss >> num;

        if(choice == "exit"){
            break;
        }

        PassChoiceToProgramList(num);
    }

    return 0;
}