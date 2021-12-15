#include <bits/stdc++.h>
using namespace std;

vector<int> t;

void update(int l, int r, int v, int x, int lx, int rx) {
    if (lx >= r || l >= rx) return;
    if (lx >= l && rx <= r) {
        t[x] = max(t[x], v);
        return;
    }
    int m = (lx + rx) >> 1;
    update(l, r, v, (x << 1) + 1, lx, m);
    update(l, r, v, (x << 1) + 2, m, rx);
}

int get(int i, int x, int lx, int rx) {
    if (rx - lx == 1) return t[x];
    int m = (lx + rx) >> 1;
    if (i < m) return max(t[x], get(i, (x << 1) + 1, lx, m));
    return max(t[x], get(i, (x << 1) + 2, m, rx));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    t.assign(n << 2, 0);
    while (m--) {
        int x;
        cin >> x;
        if (x == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            update(l, r, v, 0, 0, n);
        } else {
            int i;
            cin >> i;
            cout << get(i, 0, 0, n) << '\n';
        }
    }
    return 0;
}