#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        long long r, b, d;
        cin >> r >> b >> d;
        // in every bag r > 1, b > 1, |r - b| <= d
        // Suppose r > b.
        // b bags (1, 1), (1, 1), ..., (1, 1), with k = r - b red left.
        if (r < b) swap(r, b);
        cout << (b * d >= r - b ? "YES" : "NO") << '\n';
    }
    return 0;
}
