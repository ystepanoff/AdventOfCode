#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<bool>> q(n, vector<bool>(n, false));
    for (int t = 0; t < 2; t++) {
        for (int i = 0; i < n; i++)
            for (int l = i, r = i + t; l >= 0 && r < n; l--, r++) {
                if (s[l] == s[r]) {
                    q[l][r] = true;
                } else {
                    break;
                }
            }
    }
    vector<int> dp(n + 1, 1e9);
    vector<int> p(n + 1, 0);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (q[j - 1][i - 1] && dp[i] > dp[j - 1] + 1) {
                dp[i] = dp[j - 1] + 1;
                p[i] = i - j + 1;
            }
        }
    }
    cout << dp[n] << '\n';
    vector<string> result;
    for (int i = n; i > 0; i -= p[i]) {
        result.push_back(s.substr(i - p[i], p[i]));
    }
    reverse(result.begin(), result.end());
    for (string &s : result)
        cout << s << ' ';
    cout << '\n';
    return 0;
}
