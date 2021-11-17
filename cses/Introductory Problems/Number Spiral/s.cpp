#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        long long x, y;
        cin >> x >> y;
        long long t = max(x, y);
        if (t & 1) {
            cout << (x >= y ? (t - 1) * (t - 1) + y : t * t - x + 1) << '\n';
        } else {
            cout << (x >= y ? t * t - y + 1 : (t - 1) * (t - 1) + x) << '\n';
        }
    }
    return 0;
}
