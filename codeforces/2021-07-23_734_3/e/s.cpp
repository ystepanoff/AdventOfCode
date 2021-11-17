#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= i; j++) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + (int)(a[i] == j + 1));
            }
        int steps = -1;
        for (int j = n; j >= 0; j--)
            if (dp[n][j] >= k) {
                steps = n - j;
                break;
            }
        cout << steps << '\n';
    }
    return 0;
}
