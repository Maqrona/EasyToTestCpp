/**
 * N 個の整数を適当に足して W にすることができるか.
 */

#include <bits/stdc++.h>

#define PRINT(var) \
    std::cout << #var << ": " << var << std::endl;

bool func(int i, int w, const std::vector<int> &array) {

    if (i == 0) {
        if (w == 0) return true;
        else        return false;
    }

    if (func(i - 1, w, array))
        return true;

    if (func(i - 1, w - array[i - 1], array))
        return true;

    return false;

}

int main() {

    int N, W;
    std::cin >> N >> W;

    std::vector<int> array(N);
    for (auto && e : array) std::cin >> e;

    if (func(N, W, array))
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
}