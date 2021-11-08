#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long x, y, c;
    cin >> x >> y >> c;
    if (c > x + y) {
        cout << "Impossible\n";
    } else {
        if (c <= x) {
            cout << c << ' ' << 0 << '\n';
            return 0;
        }
        if (c <= y) {
            cout << 0 << ' ' << c << '\n';
            return 0;
        }
        if (c - x <= y) {
            cout << x << ' ' << c - x << '\n';
        } else {
            cout << c - y << ' ' << y << '\n';
        }
    }
    return 0;
}
