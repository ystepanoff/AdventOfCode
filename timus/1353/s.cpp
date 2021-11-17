#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<long long>> dp(10, vector<long long>(90, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j <= 9 * i; j++) {
            for (int k = 0; k <= 9; k++) {
                if (j >= k) dp[i][j] += dp[i - 1][j - k]; 
            }
        }
    }
    cout << dp[9][n] + (int)(n == 1) << '\n';
    return 0;
}
