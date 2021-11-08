#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        bool dp[n + 1][a][b][2 * n + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < a; j++) {
                for (int k = 0; k < b; k++) {
                    for (int x = 0; x < 2 * n + 1; x++) {
                        dp[i][j][k][x] = false;
                    }
                }
            }
        }
        char let[n + 1][a][b][2 * n + 1];
        array<int, 4> pr[n + 1][a][b][2 * n + 1];
        dp[0][0][0][n] = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < a; j++) {
                for (int k = 0; k < b; k++) {
                    for (int x = 1; x < 2 * n; x++) {
                        if (!dp[i][j][k][x]) continue;
                        
                        int nj = (j * 10 + s[i] - '0') % a;
                        dp[i + 1][nj][k][x + 1] = true;
                        let[i + 1][nj][k][x + 1] = 'R';
                        pr[i + 1][nj][k][x + 1] = { i, j, k, x };
                        
                        int nk = (k * 10 + s[i] - '0') % b;
                        dp[i + 1][j][nk][x - 1] = true;
                        let[i + 1][j][nk][x - 1] = 'B';
                        pr[i + 1][j][nk][x - 1] = { i, j, k, x };
                    }
                }
            }
        }
        int best = -1;
        for (int i = 1; i < 2 * n; i++) {
            if (dp[n][0][0][i]) {
                if (best == -1 || abs(i - n) < abs(best - n))
                    best = i;
            }
        }
        if (best == -1) {
            cout << "-1\n";
        } else {
            string result = "";
            array<int, 4> curr = { n, 0, 0, best };
            for (int i = 0; i < n; i++) {
                result += let[curr[0]][curr[1]][curr[2]][curr[3]];
                curr = pr[curr[0]][curr[1]][curr[2]][curr[3]];
            }
            reverse(result.begin(), result.end());
            cout << result << '\n';
        }
    }
    return 0;
}
