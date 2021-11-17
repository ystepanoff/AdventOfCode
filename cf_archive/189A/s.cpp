#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> dp(n + 1, -1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int x : {a, b, c})
            if (i >= x)
                dp[i] = max(dp[i], dp[i - x] + 1);
    cout << dp[n] << '\n';
    return 0;
}
