#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long m;
    cin >> n >> m;
    vector<long long> dp(n + 1, 0);
    long long s = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i] + s) % m;
        for (int j = 2; j < i / j; j++)
            dp[i] = (dp[i] + dp[i / j]) % m;
        for (int j = 1; j <= i / j; j++) {
            long long l = (i / j) - (i / (j + 1));
            dp[i] = (dp[i] + l * dp[j]) % m;
        }
        s += dp[i];
    }
    cout << dp[n] << '\n';
    return 0;
}
