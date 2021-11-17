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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (n & 1) {
            vector<pair<int,int>> b(n);
            for (int i = 0; i < n; i++) {
                b[i].first = a[i];
                b[i].second = i;
            }
            sort(b.begin(), b.end(), [](auto &x, auto &y) {
                return abs(x.first) < abs(y.first);
            });
            int x = b[0].first;
            int y = b[1].first;
            int z = b[2].first;
            b[0].first = y - z;
            b[1].first = -x;
            b[2].first = x;
            if (y == z) {
                b[0].first = y - 2 * z;
                b[1].first = -x;
                b[2].first = 2 * x;
            }
            for (int i = 3; i < n; i += 2) {
                x = b[i].first;
                y = b[i + 1].first;
                b[i].first = y;
                b[i + 1].first = -x;
            }
            sort(b.begin(), b.end(), [](auto &u, auto &v) {
                return u.second < v.second;
            });
            for (int i = 0; i < n; i++) {
                cout << b[i].first << ' ';
            }
            cout << '\n';
        } else {
            for (int i = 0; i < n; i += 2) {
                cout << a[i + 1] << ' ' << -a[i] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
