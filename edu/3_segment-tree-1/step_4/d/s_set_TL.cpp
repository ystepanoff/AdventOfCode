#include <bits/stdc++.h>
using namespace std;

vector<set<int>> t;

auto op = [](auto &a, auto &b) {
    set<int> r;
    r.insert(a.begin(), a.end());
    r.insert(b.begin(), b.end());
    return r;
};

void build(vector<int> &a, int x, int lx, int rx) {
    if (rx - lx == 1) {
        t[x].insert(a[lx]);
        return;
    }
    int m = (lx + rx) >> 1;
    build(a, (x << 1) + 1, lx, m);
    build(a, (x << 1) + 2, m, rx);
    t[x] = op(t[(x << 1) + 1], t[(x << 1) + 2]);
}

void update(int i, set<int> &v, int x, int lx, int rx) {
    if (rx - lx == 1) {
        t[x] = v;
        return;
    }
    int m = (lx + rx) >> 1;
    if (i < m)
        update(i, v, (x << 1) + 1, lx, m);
    else
        update(i, v, (x << 1) + 2, m, rx);
    t[x] = op(t[(x << 1) + 1], t[(x << 1) + 2]);
}

set<int> query(int l, int r, int x, int lx, int rx) {
    if (lx >= r || l >= rx)
        return set<int>();
    if (lx >= l && rx <= r)
        return t[x];
    int m = (lx + rx) >> 1;
    auto a = query(l, r, (x << 1) + 1, lx, m);
    auto b = query(l, r, (x << 1) + 2, m, rx);
    return op(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    t.assign(n << 2, set<int>());
    build(a, 0, 0, n);
    while (m--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            auto s = query(x - 1, y, 0, 0, n);
            cout << s.size() << '\n';
        } else {
            set<int> s({ y });
            update(x - 1, s, 0, 0, n);
        }
    }
    return 0;
}
