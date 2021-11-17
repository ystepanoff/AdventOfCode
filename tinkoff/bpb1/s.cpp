#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7;
long long dp1[1010][1010], dp2[1010][1010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, b, h;
    cin >> n >> b >> h;
    if (n <= b) {
        cout << (n == b ? 1 : 0) << '\n';
        return 0;
    }
    dp1[b][b] = 1;
    for (int i = 2; i <= h; i++) {
        memset(dp2, 0, sizeof(dp2));
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++) {
                if (j + k + 1 <= n) dp2[j + k + 1][k + 1] = (dp2[j + k + 1][k + 1] + dp1[j][k]) % mod;
                if (j + k - 1 <= n && k > 1) dp2[j + k - 1][k - 1] = (dp2[j + k - 1][k - 1] + dp1[j][k]) % mod;
            }
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                dp1[j][k] = dp2[j][k];
    }
    long long total = 0;
    for (int i = 1; i <= n; i++)
        total = (total + dp1[n][i]) % mod;
    cout << total << '\n';
    return 0;
}
