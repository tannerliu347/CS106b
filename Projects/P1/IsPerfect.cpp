#include <vector>
#include <iostream>

using namespace std;

/*
 * find all divisors
 * add to find sum
 * check equal
 */
bool isPerfect(int n) {
    int sum = 1;
    for (int i = 2; i * i < n; i++) {
        if (n % i == 0) {
            if (i * i != n) sum = sum + i + n / i;
            else sum = sum + i;
        }
    }
    return (n != 1) && (n == sum);
}

//int main() {
//    for (int i = 1; i <= 10000; i++) {
//        if (isPerfect(i))
//            cout << i << endl;
//    }
//    return 0;
//}
