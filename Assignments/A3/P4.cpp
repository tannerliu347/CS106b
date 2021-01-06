#include <iostream>

using namespace std;

int cannonball(int height) {
    if (height == 1)
        return 1;
    return height * height + cannonball(height - 1);
}

//int main() {
//    cout << cannonball(3);
//    return 0;
//}
