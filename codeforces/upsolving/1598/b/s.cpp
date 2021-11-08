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
        vector<vector<int>> a(n, vector<int>(5));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> a[i][j];
            }
        }
        int m = n >> 1;
        bool yes = false;
        for (int x = 0; x < 5; x++) {
            for (int y = x + 1; y < 5; y++) {
                int bx = 0, by = 0, b = 0;
                for (int i = 0; i < n; i++) {
                    if (a[i][x] + a[i][y] == 1) {
                        if (a[i][x]) bx++;
                        if (a[i][y]) by++;
                    } else if (a[i][x] + a[i][y] == 2) {
                        b++;
                    }
                }
                if (b >= max(0, m - bx) + max(0, m - by)) yes = true;
            }
        }
        cout << (yes ? "YES" : "NO") << '\n';
    }
    return 0;
}
