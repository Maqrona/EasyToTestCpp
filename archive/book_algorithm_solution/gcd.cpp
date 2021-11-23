/**
 *  最大公約数を求める
 */
#include <bits/stdc++.h>

#define PRINT(var) \
    std::cout << #var << ": " << var << std::endl;

int gcd(int m, int n) {

    /**
     * 51 = 15 * 3 + 6
     * 15 =  6 * 2 + 3
     *  6 =  3 * 2 + 0
     *  3 =  0 * ? + ? => return m;
    */
    if (n == 0) return m;

    return gcd(n, m % n);
}

int main() {

    PRINT(gcd(51, 15));
}