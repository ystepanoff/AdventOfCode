#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int m;
        cin >> m;
        vector<vector<long long>> a(2, vector<long long>(m));
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        vector<vector<long long>> b(2, vector<long long>(m, 0));
        b[0][0] = a[0][0];
        b[1][0] = a[1][0];
        for (int j = 1; j < m; j++) {
            b[0][j] = b[0][j - 1] + a[0][j];
            b[1][j] = b[1][j - 1] + a[1][j];
        }
        long long best = 1e18;
        for (int j = 0; j < m; j++) {
            long long c = 0;
            if (j == 0) {
                c = b[0][m - 1] - b[0][0]; 
            } else if (j == m - 1) {
                c = b[1][m - 2];
            } else {
                c = max(b[0][m - 1] - b[0][j], b[1][j - 1]);
            }
            if (c < best)
                best = c;
        }
        cout << best << '\n';
    }
    return 0;
}
