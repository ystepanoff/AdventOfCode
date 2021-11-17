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
    if (i < m)
        update(i, v, (x << 1) + 1, lx, m);
    else
        update(i, v, (x << 1) + 2, m, rx);
    t[x] = min(t[(x << 1) + 1], t[(x << 1) + 2]);
}

int get_min(int l, int r, int x, int lx, int rx) {
    if (lx >= r || l >= rx)
        return INT_MAX;
    if (lx >= l && rx <= r)
        return t[x];
    int m = (lx + rx) >> 1;
    return min(get_min(l, r, (x << 1) + 1, lx, m), 
               get_min(l, r, (x << 1) + 2, m, rx));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    t.assign(n << 2, INT_MAX);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    build(a, 0, 0, n);
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 1) {
            update(y, z, 0, 0, n);
        } else {
            cout << get_min(y, z, 0, 0, n) << '\n';
        }
    }
    return 0;
}
