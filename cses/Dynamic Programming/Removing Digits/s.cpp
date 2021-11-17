#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int x = i; x > 0; x /= 10)
            dp[i] = min(dp[i], dp[i - (x % 10)] + 1);
    cout << dp[n] << '\n';
    return 0;
}
