#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> cheat(n + 1, vector<bool> (m + 1, false));
    int k;
    cin >> k;
    while (k--) {
        int x, y;
        cin >> x >> y;
        cheat[x][y] = true;
    }
    vector<vector<double>> dp(n + 1, vector<double> (m + 1, 0));
    for (int i = 1; i <= n; i++)
        dp[i][0] = dp[i-1][0] + 100;
    for (int j = 1; j <= m; j++)
        dp[0][j] = dp[0][j-1] + 100;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 100;
            if (cheat[i][j])
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 100 * sqrt(2.0));
        }
    cout << (int)(dp[n][m] + 0.5) << "\n";
    return 0;
}
