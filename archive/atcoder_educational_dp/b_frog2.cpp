//
//  B - Frog 2
//

#include <bits/stdc++.h>

constexpr int INF = std::numeric_limits<int>::max();

int main() {

    int N, K;
    std::cin >> N >> K;
    std::vector<int> h(N), dp(N, INF);
    for (auto &&e : h) std::cin >> e;
    dp[0] = 0;

    for (int i = 0; i < N; i++) {

        for (int j = 1; j <= K; j++) {

            // 配列の境界外を参照しなかったら
            if (i + j < N) {
                dp[i + j] = std::min(dp[i + j], dp[i] + std::abs(h[i + j] - h[i]));
            }
        }
    }

    std::cout << dp[N - 1] << std::endl;
}