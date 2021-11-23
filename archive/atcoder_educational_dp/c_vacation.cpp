//
//  C - Vacation
//

#include <bits/stdc++.h>

int main() {

    int N;
    std::cin >> N;

    std::vector<std::vector<int>> h(N, std::vector<int>(3)), dp(N + 1, std::vector<int>(3, 0));
    for (auto &&e : h) std::cin >> e[0] >> e[1] >> e[2];

    for (int i = 0; i < N; i++) {

        dp[i + 1][0] = std::max(dp[i][1] + h[i][0], dp[i][2] + h[i][0]);
        dp[i + 1][1] = std::max(dp[i][0] + h[i][1], dp[i][2] + h[i][1]);
        dp[i + 1][2] = std::max(dp[i][0] + h[i][2], dp[i][1] + h[i][2]);
    }

    std::cout << std::max(std::max(dp[N][0], dp[N][1]), dp[N][2]) << std::endl;
}