#include <bits/stdc++.h>
using namespace std;

vector<int> t;

void build(vector<int> &a, int x, int lx, int rx) {
    if (rx - lx == 1) {
        t[x] = a[lx];
        return;
    }
    int m = (lx + rx) >> 1;
    build(a, (x << 1) + 1, lx, m);
    build(a, (x << 1) + 2, m, rx);
    t[x] = t[(x << 1) + 1] ^ t[(x << 1) + 2];
}

int query(int l, int r, int x, int lx, int rx) {
    if (l >= rx || lx >= r) return 0;
    if (lx >= l && rx <= r) return t[x];
    int m = (lx + rx) >> 1;
    return query(l, r, (x << 1) + 1, lx, m) ^ query(l, r, (x << 1) + 2, m, rx);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    t.assign(n << 2, 0);
    build(a, 0, 0, n);
    while (q--) {
        int i, j;
        cin >> i >> j;
        cout << query(i - 1, j, 0, 0, n) << '\n';
    }
    return 0;
}
