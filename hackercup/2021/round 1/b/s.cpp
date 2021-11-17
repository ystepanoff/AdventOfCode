#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    for (int _t = 1; _t <= tt; _t++) {
        cout << "Case #" << _t << ": ";
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        vector<vector<int>> grid(n, vector<int>(m, 1));
        int total = n + m - 2;
        if (total + 1 > a || total + 1 > b) {
            cout << "Impossible\n";
        } else {
            cout << "Possible\n";
            if (a > total) grid[0][0] = a - total;
            if (b > total) grid[0][m - 1] = b - total;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << grid[i][j];
                    if (j + 1 < m) cout << ' ';
                }
                cout << '\n';
            }
        }
    }
    return 0;
}
