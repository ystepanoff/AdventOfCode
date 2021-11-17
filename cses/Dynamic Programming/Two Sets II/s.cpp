#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int s = n * (n + 1);
    if (s % 4 != 0) {
        cout << "0\n";
        return 0;
    }
    s >>= 2;
    vector<int> dp(s + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = s; j >= i; j--)
            dp[j] = (dp[j] + dp[j - i]) % MOD;
    cout << ((long long)dp[s] * (long long)((MOD + 1) / 2)) % (long long)MOD << '\n';
    return 0;
}
