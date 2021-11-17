#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = a[i]; j <= x; j++)
            dp[j] = (dp[j] + dp[j - a[i]]) % mod;
    cout << dp[x] << '\n';
    return 0;
}
