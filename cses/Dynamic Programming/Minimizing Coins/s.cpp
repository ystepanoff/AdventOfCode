#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> dp(x + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
        for (int y : a)
            if (i >= y)
                dp[i] = min(dp[i], dp[i - y] + 1);
    cout << (dp[x] == 1e9 ? -1 : dp[x]) << '\n';
    return 0;
}
