#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<int>> dp(n, vector<int> (n, 0));
    for (int i = 0; i < n; i++) {
        if (a[i][0] == '*') break;
        dp[i][0] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (a[0][i] == '*') break;
        dp[0][i] = 1;
    }
    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
            if (a[i][j] != '*')
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;;
    cout << dp[n - 1][n - 1] << '\n';
    return 0;
}
