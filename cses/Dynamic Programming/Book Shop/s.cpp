#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> h(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    vector<vector<int>> dp(n + 1, vector<int> (x + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= x; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= h[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - h[i]] + s[i]);
        }
    cout << dp[n][x] << '\n';
    return 0;
}
