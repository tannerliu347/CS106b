/*
 * File: main.cpp
 * --------------
 * Sample QT project
 */

#include <iostream>
#include "console.h"
using namespace std;

struct Cell {
    int val;
    Cell *next;

    Cell(int value) {
        val = value;
        next = nullptr;
    }
};

void append(Cell *&l1, Cell *l2) {
    if (l1 == nullptr)
        l1 = l2;
    else
        append(l1->next, l2);
}

void printList(Cell *head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
}
/*
 * This sample main brings up testing menu.
 */
int main() {
    Cell *l1 = new Cell(1);
    Cell *l12 = new Cell(4);
    Cell *l13 = new Cell(6);
    l1->next = l12;
    l12->next = l13;
    // list 2
    Cell *l2 = new Cell(3);
    Cell *l22 = new Cell(19);
    Cell *l23 = new Cell(2);
    l2->next = l22;
    l22->next = l23;
    append(l1, l2);
    printList(l1);
    return 0;
}
