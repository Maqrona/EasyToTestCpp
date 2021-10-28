#include <bits/stdc++.h>

#define PRINT(var) \
    std::cout << #var << ": " << var << std::endl;

using big_t = long long;

big_t fibo(int n) {

    static std::unordered_map<int, big_t> memo;

    if      (n == 0) return 0;
    else if (n == 1) return 1;

    // 初めて計算したときには, メモする
    if (memo.count(n) == 0)
        memo.emplace(n, fibo(n - 1) + fibo(n - 2));

    return memo[n];
}

int main() {

    PRINT(fibo(50));
}
