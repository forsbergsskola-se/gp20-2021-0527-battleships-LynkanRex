//
// Created by Lynkan on 2021-06-01.
//

#include "programlist.h"
#include "fibonacci.h"
#include "random.h"

void PassChoiceToProgramList(int choice){
    switch (choice) {
        case 1:
            RunFibonacci();
            break;
        case 2:
            RunRandom();
            break;
        default:
            break;
    }
}