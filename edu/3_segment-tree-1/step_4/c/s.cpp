#include <bits/stdc++.h>
using namespace std;

struct node {
    long long inv = 0;
    int cnt[41] = { 0 };

    node() { }

    node(int v) {
        cnt[v] = 1;
    }
};

node op(node &a, node &b) {
    node c;
    c.inv = a.inv + b.inv;
    for (int i = 1; i < 41; i++)
        for (int j = 1; j < i; j++)
            c.inv += (long long)a.cnt[i] * (long long)b.cnt[j];
    for (int i = 1; i < 41; i++)
        c.cnt[i] = a.cnt[i] + b.cnt[i];
    return c;
}

vector<node> t;

void build(vector<int> &a, int x, int lx, int rx) {
    if (rx - lx == 1) {
        t[x] = node(a[lx]);
        return;
    }
    int m = (lx + rx) >> 1;
    build(a, (x << 1) + 1, lx, m);
    build(a, (x << 1) + 2, m, rx);
    t[x] = op(t[(x << 1) + 1], t[(x << 1) + 2]);
}

void update(int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1) {
        t[x] = node(v);
        return;
    }
    int m = (lx + rx) >> 1;
    if (i < m)
        update(i, v, (x << 1) + 1, lx, m);
    else
        update(i, v, (x << 1) + 2, m, rx);
    t[x] = op(t[(x << 1) + 1], t[(x << 1) + 2]);
}

node query(int l, int r, int x, int lx, int rx) {
    if (lx >= r || l >= rx)
        return node();
    if (lx >= l && rx <= r)
        return t[x];
    int m = (lx + rx) >> 1;
    node a = query(l, r, (x << 1) + 1, lx, m);
    node b = query(l, r, (x << 1) + 2, m, rx);
    return op(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    t.assign(n << 2, node());
    build(a, 0, 0, n);
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            auto c = query(x - 1, y, 0, 0, n);
            cout << c.inv << '\n';
        } else {
            update(x - 1, y, 0, 0, n);
        }
    }
    return 0;
}
