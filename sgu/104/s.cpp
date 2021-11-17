#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int f, v;
    cin >> f >> v;
    vector<vector<int>> a(f + 1, vector<int>(v + 1));
    for (int i = 1; i <= f; i++)
        for (int j = 1; j <= v; j++)
            cin >> a[i][j];
    vector<vector<int>> dp(f + 1, vector<int>(v + 1, -1e9)), p(f + 1, vector<int>(v + 1, 0));
    for (int j = 0; j <= v; j++)
        dp[0][j] = 0;
    for (int i = 1; i <= f; i++)
        for (int j = 1; j <= v; j++)
            if (dp[i - 1][j - 1] + a[i][j] > dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + a[i][j];
                p[i][j] = 1;
            } else {
                dp[i][j] = dp[i][j - 1];
                p[i][j] = 2;
            }
    cout << dp[f][v] << '\n';
    vector<int> r;
    for (int i = f, j = v; i > 0; ) {
        if (p[i][j] == 1) {
            r.push_back(j);
            i--, j--;
        } else {
            j--;
        }
    }
    reverse(r.begin(), r.end());
    for (int x : r)
        cout << x << ' ';
    cout << '\n';
    return 0;
}
