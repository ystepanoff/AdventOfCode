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
    t[x] = min(t[(x << 1) + 1], t[(x << 1) + 2]);
}

void update(int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1) {
        t[x] = v;
        return;
    }
    int m = (lx + rx) >> 1;
    if (i < m) update(i, v, (x << 1) + 1, lx, m);
    else update(i, v, (x << 1) + 2, m, rx);
    t[x] = min(t[(x << 1) + 1], t[(x << 1) + 2]);
}

int query(int l, int r, int x, int lx, int rx) {
    if (l >= rx || lx >= r) return INT_MAX;
    if (lx >= l && rx <= r) return t[x];
    int m = (lx + rx) >> 1;
    return min(query(l, r, (x << 1) + 1, lx, m),
               query(l, r, (x << 1) + 2, m, rx));
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
    t.assign(n << 2, INT_MAX);
    build(a, 0, 0, n);
    while (q--) {
        int x, i, j;
        cin >> x >> i >> j;
        if (x == 1) {
            update(i - 1, j, 0, 0, n);
        } else {
            cout << query(i - 1, j, 0, 0, n) << '\n';
        }
    }
    return 0;
}
