#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = -1e9, r = 1e9;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            if (l == -1e9 || a[i] > l) l = a[i];
        } else {
            if (r == 1e9 || a[i] < r) r = a[i];
        }
    }
    if (x > 0) {
        if (x > r) {
            cout << "Impossible\n";
        } else {
            cout << x << ' ' << - 2 * l + x << '\n';
        }
    } else {
        if (x < l) {
            cout << "Impossible\n";
        } else {
            cout << 2 * r - x << ' ' << -x << '\n';
        }
    }
    return 0;
}
