/*
 * File: main.cpp
 * --------------
 * Sample QT project
 */

#include <iostream>
#include "console.h"
using namespace std;

void printInBinary(int num) {
    if (num  == 0)
        return;
    int curDig = num % 2;
    printInBinary(num / 2);
    cout << curDig << " ";
}

//int main() {
//    printInBinary(6);
//    return 0;
//}
