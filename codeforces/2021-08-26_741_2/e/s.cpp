#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        string s;
        cin >> n >> s;
        vector<vector<int>> lcp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--) 
            for (int j = n - 1; j >= 0; j--)
                if (i == j)
                    lcp[i][j] = n - i;
                else if (s[i] == s[j])
                    lcp[i][j] = lcp[i + 1][j + 1] + 1;
        vector<int> dp(n, 0);
        iota(dp.rbegin(), dp.rend(), 1);
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++) {
                int l = lcp[i][j];
                if (i + l < n && j + l < n && s[j + l] < s[i + l])
                    dp[i] = max(dp[i], dp[j] + n - i - l);
            }
        cout << *max_element(dp.begin(), dp.end()) << '\n';
    }
    return 0;
}
