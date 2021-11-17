#include <bits/stdc++.h>
using namespace std;

int dp[901][8101], p[901][8101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < 901; i++)
        for (int j = 0; j < 8101; j++) {
            dp[i][j] = 1e9;
            p[i][j] = -1;
        }
    dp[0][0] = 0;
    for (int i = 1; i < 901; i++)
        for (int j = 1; j < 8101; j++) 
            for (int k = 1; k <= 9; k++) {
                if (i >= k && j >= k * k && dp[i - k][j - k * k] + 1 < dp[i][j]) {
                    dp[i][j] = dp[i - k][j - k * k] + 1;
                    p[i][j] = k;
                }
            }
    int tt;
    cin >> tt;
    while (tt--) {
        int s1, s2;
        cin >> s1 >> s2;
        if (s1 > 900 || s2 > 8100 || dp[s1][s2] > 100) {
            cout << "No solution\n";
            continue;
        }
        int l = dp[s1][s2];
        while (l--) {
            int d = p[s1][s2];
            cout << d;
            s1 -= d;
            s2 -= d * d;
        }
        cout << '\n';
    }
    return 0;
}
