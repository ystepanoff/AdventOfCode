#include <bits/stdc++.h>
using namespace std;
 
struct node {
    int cnt[41] = { 0 };
};
node ZERO;
 
vector<node> t;
 
auto op(node a, node b) {
    node c;
    for (int i = 0; i < 41; i++)
        c.cnt[i] = a.cnt[i] + b.cnt[i];
    return c;
}
 
void update(int i, node &v, int x, int lx, int rx) {
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
 
node query(int l, int r, int x, int lx, int rx) {
    if (lx >= r || l >= rx)
        return ZERO;
    if (lx >= l && rx <= r)
        return t[x];
    int m = (lx + rx) >> 1;
    return op(query(l, r, (x << 1) + 1, lx, m),
              query(l, r, (x << 1) + 2, m, rx));
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    t.assign(n << 2, ZERO);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        node v;
        v.cnt[x] = 1;
        update(i, v, 0, 0, n);
    }
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            auto v = query(x - 1, y, 0, 0, n);
            int total = 0;
            for (int i = 0; i < 41; i++)
                total += (int)(v.cnt[i] > 0);
            cout << total << '\n';
        } else {
            node v;
            v.cnt[y] = 1;
            update(x - 1, v, 0, 0, n);
        }
    }
    return 0;
}
