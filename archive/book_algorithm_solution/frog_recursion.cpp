/**
 *  N 個の足場, i 番目の高さは h_i, カエルの初期位置は 0 番目,
 *    足場 i -> i+1 へのコスト: |h_i - h_{i+1}|
 *    足場 i -> i+2 へのコスト: |h_i - h_{i+2}|
 *  カエルが N-1 番目の足場にたどり着くまでのコストの最小値
 */

#include <bits/stdc++.h>

#define PRINT(var) \
    std::cout << #var << ": " << var << std::endl;

// クソでか数の型
using big_t = long long;

// クソでか数
const big_t INF = 1LL << 60;

int N;
std::vector<big_t> h, dp;

template <typename T>
void ch_min(T& a, T b) {
    if (a > b) a = b;
}

big_t rec(int i) {

    // DP の値が更新されていたらそのまま return
    if (dp[i] < INF) return dp[i];

    // ベースケース, 足場 0 のコストは 0
    if (i == 0) return 0;

    big_t result = INF;

    // 足場 i-1 から来た場合
    ch_min(result, rec(i-1) + std::abs(h[i] - h[i-1]));

    // 足場 i-2 から来た場合
    if (i > 1) ch_min(result, rec(i-2) + std::abs(h[i] - h[i-2]));

    // 結果をメモしたうえで返す
    return dp[i] = result;
}

int main() {

    std::cin >> N;
    h.resize(N);
    for (auto &&e : h) std::cin >> e;

    dp.assign(N, INF);

    std::cout << rec(N-1) << std::endl;
}