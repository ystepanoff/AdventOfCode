#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n, 0);
    b[0] = a[0];
    for (int i = 1; i < n; i++)
        b[i] = b[i - 1] + a[i];
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++) {
            for (int x = j - 1; x < i; x++) {
                int c0 = i - x - b[i - 1] + b[x];
                int c1 = b[i - 1] - b[x];
                dp[i][j] = min(dp[i][j], dp[x][j - 1] + c0 * c1);
            }
        }
    cout << dp[n][k] << '\n';
    return 0;
}
