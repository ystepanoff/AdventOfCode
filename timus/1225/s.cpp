#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<long long>> dp(n + 1, vector<long long>(4, 0));
    // dp[n][0] -- red
    // dp[n][1] -- white
    // dp[n][2] -- red-blue
    // dp[n][3] -- white-blue
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][1] + dp[i - 1][3];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
        dp[i][2] = dp[i - 1][0];
        dp[i][3] = dp[i - 1][1];
    }
    cout << dp[n][0] + dp[n][1] << '\n';
    return 0;
}
