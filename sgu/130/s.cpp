#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    vector<long long> dp(k + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= k; i++)
        for (int j = 0; j < i; j++)
            dp[i] += dp[j] * dp[i - j - 1];
    cout << dp[k] << ' ' << k + 1 << '\n';
    return 0;
}
