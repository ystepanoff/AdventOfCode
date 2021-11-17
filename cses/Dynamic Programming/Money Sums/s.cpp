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
    int m = accumulate(a.begin(), a.end(), 0);
    vector<bool> dp(m + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++)
        for (int j = m; j >= a[i]; j--)
            dp[j] = dp[j] or dp[j - a[i]];
    vector<int> b;
    for (int i = 1; i <= m; i++)
        if (dp[i])
            b.push_back(i);
    cout << b.size() << '\n';
    for (int x : b)
        cout << x << ' ';
    cout << '\n';
    return 0;
}
