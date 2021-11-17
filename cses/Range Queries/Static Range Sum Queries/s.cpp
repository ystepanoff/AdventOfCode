#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i)
            a[i] += a[i - 1];
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << (a[y - 1] - (x > 1 ? a[x - 2] : 0)) << '\n';
    }
    return 0;
}
