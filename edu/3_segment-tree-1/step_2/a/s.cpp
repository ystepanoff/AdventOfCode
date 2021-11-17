#include <bits/stdc++.h>
using namespace std;

struct node {
    long long sum, seg, pref, suff;
};

node op(node a, node b) {
    return {
        a.sum + b.sum,
        max(max(a.seg, b.seg), a.suff + b.pref),
        max(a.pref, a.sum + b.pref),
        max(b.suff, b.sum + a.suff)
    };
}

vector<node> t;

void build(vector<int> &a, int x, int lx, int rx) {
    if (rx - lx == 1) {
        t[x] = { a[lx], a[lx], a[lx], a[lx] };
        return;
    }
    int m = (lx + rx) >> 1;
    build(a, (x << 1) + 1, lx, m);
    build(a, (x << 1) + 2, m, rx);
    t[x] = op(t[(x << 1) + 1], t[(x << 1) + 2]);
}

void update(int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1) {
        t[x] = { v, v, v, v };
        return;
    }
    int m = (lx + rx) >> 1;
    if (i < m)
        update(i, v, (x << 1) + 1, lx, m);
    else
        update(i, v, (x << 1) + 2, m, rx);
    t[x] = op(t[(x << 1) + 1], t[(x << 1) + 2]);
}

node max_segment(int l, int r, int x, int lx, int rx) {
    if (lx >= r || l >= rx)
        return { 0, 0, 0, 0 };
    if (l >= lx && r <= rx)
        return t[x];
    int m = (lx + rx) >> 1;
    return op(max_segment(l, r, (x << 1) + 1, lx, m),
              max_segment(l, r, (x << 1) + 2, m, rx));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    t.assign(n << 2, { 0, 0, 0, 0 });
    build(a, 0, 0, n);
    node nd = max_segment(0, n, 0, 0, n);
    cout << max(0LL, nd.seg) << '\n';
    while (m--) {
        int i, v;
        cin >> i >> v;
        update(i, v, 0, 0, n);
        nd = max_segment(0, n, 0, 0, n);
        cout << max(0LL, nd.seg) << '\n';
    }
    return 0;
}
