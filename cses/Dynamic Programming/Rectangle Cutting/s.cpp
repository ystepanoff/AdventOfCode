#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int> (b + 1, 1e9));
    for (int A = 1; A <= a; A++)
        for (int B = 1; B <= b; B++) {
            if (A == B) {
                dp[A][B] = 0;
                continue;
            }
            int r = A * B;
            for (int i = 1; i < A; i++)
                r = min(r, dp[i][B] + dp[A - i][B]);
            for (int i = 1; i < B; i++)
                r = min(r, dp[A][i] + dp[A][B - i]);
            dp[A][B] = r + 1;
        }
    cout << dp[a][b] << '\n';
    return 0;
}
