#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> dp(1 << n, 1e9);
    dp[0] = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            int submask = 0;
            submask |= 1 << i;
            submask |= 1 << ((i + 1) % n);
            submask |= 1 << ((i + 2) % n);
            if (mask & submask) {
                int v = 0, oldmask = mask;
                for (int j = 0; j < n; j++) {
                    if (mask & (1 << j)) {
                        v += a[j];
                        if (submask & (1 << j)) {
                            v -= a[j];
                            oldmask ^= (1 << j);
                        }
                    }
                }
                dp[mask] = min(dp[mask], dp[oldmask] + v);
            }
        }
    }
    cout << dp[(1 << n) - 1] << '\n';
    return 0;
}
