#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int k;
    cin >> k;
    vector<string> a(k);
    for (int i = 0; i < k; i++)
        cin >> a[i];
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < k; j++) {
            int l = a[j].size();
            if (i - l >= 0) {
                bool match = true;
                for (int k = 0; k < l; k++)
                    if (s[k + i - l] != a[j][k]) {
                        match = false;
                        break;
                    }
                if (match)
                    dp[i] = (dp[i] + dp[i - l]) % mod;
            }
        }
    cout << dp[n] << '\n';
    return 0;
}
