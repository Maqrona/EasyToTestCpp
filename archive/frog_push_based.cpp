/**
 *  N 個の足場, i 番目の高さは h_i, カエルの初期位置は 0 番目,
 *    足場 i -> i+1 へのコスト: |h_i - h_{i+1}|
 *    足場 i -> i+2 へのコスト: |h_i - h_{i+2}|
 *  カエルが N-1 番目の足場にたどり着くまでのコストの最小値
 */

#include <bits/stdc++.h>

#define PRINT(var) \
    std::cout << #var << ": " << var << std::endl;

template <typename T>
void ch_min(T& a, T b) {
    if (a > b) a = b;
}

// クソでか数の型
using big_t = long long;

// クソでか数
const big_t INF = 1LL << 60;

int main() {

    int N;
    std::cin >> N;
    std::vector<big_t> h(N);

    for (auto &&e : h) std::cin >> e;

    std::vector<big_t> dp(N, INF);
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        if (i+1 < N)
            ch_min(dp[i+1], dp[i] + std::abs(h[i] - h[i+1]));
        if (i+2 < N)
            ch_min(dp[i+2], dp[i] + std::abs(h[i] - h[i+2]));
    }

    std::cout << dp[N-1] << std::endl;
}