#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m, k;
        cin >> n >> m >> k;
        if (!(n & 1) && !(m & 1)) {
            if (!(k & 1)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            if (m & 1) {
                swap(n, m);
                k = (n * m) / 2 - k;
            }
            if (k >= m / 2 && !((k - m / 2) & 1)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}
