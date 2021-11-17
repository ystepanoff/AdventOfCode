#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++)
        cin >> a[i];
    vector<char> dp(n + 1, 'L');
    for (int i = 1; i <= n; i++) {
        bool w = false;
        for (int j = 0; j < k; j++) 
            if (i >= a[j]) {
                w |= dp[i - a[j]] == 'L';
            }
        dp[i] = w ? 'W' : 'L';
        cout << dp[i];
    }
    cout << '\n';
    return 0;
}
