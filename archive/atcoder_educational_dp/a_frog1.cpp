//
//  A - Frog 1
//

#include <bits/stdc++.h>

constexpr int INF = std::numeric_limits<int>::max();

int main() {

    int N;
    std::cin >> N;

    std::vector<int> h(N), dp(N, INF);
    for (auto &&e : h) std::cin >> e;
    dp[0] = 0;

    // push-based
    for (int i = 0; i < N; i++) {

        if (i < N - 1) {
            dp[i + 1] = std::min(dp[i + 1], dp[i] + std::abs(h[i + 1] - h[i]));
        }

        if (i < N - 2) {
            dp[i + 2] = std::min(dp[i + 2], dp[i] + std::abs(h[i + 2] - h[i]));
        }
    }

    std::cout << dp[N - 1] << std::endl;
}