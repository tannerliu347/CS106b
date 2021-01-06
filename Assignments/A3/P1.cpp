/*
 * File: main.cpp
 * --------------
 * Sample QT project
 */

#include <iostream>
#include "set.h"
#include "console.h"
using namespace std;

struct entryT {
    string firstName;
    string lastName;
    string phoneNumber;

    entryT(string f, string l, string p) {
        firstName = f;
        lastName = l;
        phoneNumber = p;
    }
};

int compByName(entryT a, entryT b) {
    if (a.lastName < b.lastName)
        return -1;
    else if (a.lastName > b.lastName)
        return 1;
    else {
        if (a.firstName < b.firstName)
            return -1;
        else if (a.firstName > b.firstName)
            return 1;
        else
            return 0;
    }
}
/*
 * This sample main brings up testing menu.
 */
//int main() {
//    Set<entryT> testSet(compByName);
//    entryT pA("Tanner", "Liu", "404980");
//    entryT pB("Nick", "Zhang", "404780");
//    entryT pC("Tanner", "Ab", "438102");
//    entryT pD("Tanner", "Liu", "123456");
//    testSet.add(pA);
//    testSet.add(pB);
//    testSet.add(pC);
//    testSet.add(pD);
//    cout << testSet.size() << endl;
//    return 0;
//}
