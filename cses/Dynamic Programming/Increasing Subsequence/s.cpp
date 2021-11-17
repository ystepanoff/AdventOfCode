#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = INT_MIN;
    for (int i = 0; i < n; i++) {
        int j = (int)(upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin());
        if (dp[j - 1] < a[i] && a[i] < dp[j])
            dp[j] = a[i];
    }
    int best = 1;
    for (int i = 1; i <= n; i++)
        if (dp[i] < INT_MAX)
            best = i;
    cout << best << '\n';
    return 0;
}
