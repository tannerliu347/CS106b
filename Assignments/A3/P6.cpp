#include <iostream>

using namespace std;

int GCD(int x, int y) {
    if (x % y == 0)
        return y;
    return GCD(y, x / y);
}

//int main() {
//    int x = 10, y = 4;
//    cout << "Greateset common divisior of " << x << " and " << y << " is: " << GCD(x, y) << endl;
//    return 0;
//}
