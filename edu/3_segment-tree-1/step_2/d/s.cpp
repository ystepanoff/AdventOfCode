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
    t[x] = max(t[(x << 1) + 1], t[(x << 1) + 2]);
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
    t[x] = max(t[(x << 1) + 1], t[(x << 1) + 2]);
}

int first_ge(int k, int l, int x, int lx, int rx) {
    if (t[x] < k || l >= rx)
        return -1;
    if (rx - lx == 1)
        return lx;
    int m = (lx + rx) >> 1;
    int r = first_ge(k, l, (x << 1) + 1, lx, m);
    if (r == -1)
        r = first_ge(k, l, (x << 1) + 2, m, rx);
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    t.assign(n << 2, INT_MIN);
    build(a, 0, 0, n);
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 1) {
            update(y, z, 0, 0, n);
        } else {
            cout << first_ge(y, z, 0, 0, n) << '\n';
        }
    }
    return 0;
}
