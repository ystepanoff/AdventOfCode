#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> t;

auto op(pair<int,int> a, pair<int,int> b) {
    if (a.first < b.first)
        return a;
    if (b.first < a.first)
        return b;
    return make_pair(a.first, a.second + b.second);
}

void build(vector<int> &a, int x, int lx, int rx) {
    if (rx - lx == 1)  {
        t[x] = make_pair(a[lx], 1);
        return;
    }
    int m = (lx + rx) >> 1;
    build(a, (x << 1) + 1, lx, m);
    build(a, (x << 1) + 2, m, rx);
    t[x] = op(t[(x << 1) + 1], t[(x << 1) + 2]);
}

void update(int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1) {
        t[x] = make_pair(v, 1);
        return;
    }
    int m = (lx + rx) >> 1;
    if (i < m)
        update(i, v, (x << 1) + 1, lx, m);
    else
        update(i, v, (x << 1) + 2, m, rx);
    t[x] = op(t[(x << 1) + 1], t[(x << 1) + 2]);
}

auto get_min(int l, int r, int x, int lx, int rx) {
    if (lx >= r || l >= rx)
        return make_pair(INT_MAX, 0);
    if (lx >= l && rx <= r)
        return t[x];
    int m = (lx + rx) >> 1;
    return op(get_min(l, r, (x << 1) + 1, lx, m),
              get_min(l, r, (x << 1) + 2, m, rx));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    t.assign(n << 2, make_pair(INT_MAX, 0));
    build(a, 0, 0, n);
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 1) {
            update(y, z, 0, 0, n);
        } else {
            auto p = get_min(y, z, 0, 0, n);
            cout << p.first << ' ' << p.second << '\n';
        }
    }
    return 0;
}
