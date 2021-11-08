#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<string> g(2);
        for (int i = 0; i < 2; i++) {
            cin >> g[i];
        }
        vector<vector<bool>> can(2, vector<bool>(n, false));
        can[0][0] = g[0][0] == '0';
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                if (g[j][i] == '0') {
                    can[j][i] = can[0][i - 1] | can[1][i - 1];
                }
            }
        }
        cout << (can[1][n - 1] ? "YES" : "NO") << '\n';
    }
    return 0;
}
