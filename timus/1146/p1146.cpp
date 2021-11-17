#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int> (n + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    int best = a[1][1];
    vector<vector<int>> sums = a;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            sums[i][j] += sums[i][j-1];
            if (a[i][j] > best)
                best = a[i][j];
        }
    if (best < 0) {
        cout << best << '\n';
        return 0;
    }
    for (int l = 1; l <= n; l++)
        for (int r = l; r <= n; r++) {
            int s = 0;
            for (int i = 0; i <= n; i++) {
                int t = sums[i][r] - sums[i][l - 1];
                s += t;
                if (s > best)
                    best = s;
                if (s < 0)
                    s = 0;
            }
        }
    cout << best << '\n';
    return 0;
}
