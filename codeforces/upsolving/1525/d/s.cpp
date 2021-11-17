#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
        int n;
        cin >> n;
        vector<int> a(n), b;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 1) b.push_back(i);
        }
        // dp[i][j] -- considered i first seats and chose j from them
        // as newly occupied
        int m = b.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, INT_MAX));
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i + 1][j] = min(dp[i][j], dp[i + 1][j]);
                if (a[i] == 0 && j < m) {
                    dp[i + 1][j + 1] = min(dp[i][j] + abs(b[j] - i), dp[i + 1][j + 1]);
                }
            }
        }
        cout << dp[n][m] << '\n';
    return 0;
}
