#include <bits/stdc++.h>
using namespace std;

const int N = 5010;
int n, a[N];
long long dp[N][N];

long long solve(int l, int r) {
    if (l > r) return 0;
    if (dp[l][r] == -1) {
        long long x = a[l] + min(solve(l + 2, r), solve(l + 1, r - 1));
        long long y = a[r] + min(solve(l + 1, r - 1), solve(l, r - 2));
        dp[l][r] = max(x, y);
    }
    return dp[l][r];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dp[i][j] = -1;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(0, n - 1) << '\n';
    return 0;
}
