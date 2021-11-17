#include <bits/stdc++.h>
using namespace std;

vector<long long> t;

void update(int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1) {
        t[x] += v;
        return;
    }
    int m = (lx + rx) >> 1;
    if (i < m)
        update(i, v, (x << 1) + 1, lx, m);
    else
        update(i, v, (x << 1) + 2, m, rx);
    t[x] = t[(x << 1) + 1] + t[(x << 1) + 2];
}

long long get_sum(int l, int r, int x, int lx, int rx) {
    if (l >= rx || lx >= r)
        return 0;
    if (lx >= l && rx <= r)
        return t[x];
    int m = (lx + rx) >> 1;
    return get_sum(l, r, (x << 1) + 1, lx, m) +
           get_sum(l, r, (x << 1) + 2, m, rx);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    t.assign((n + 1) << 2, 0);
    while (m--) {
        int x;
        cin >> x;
        if (x == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            update(l, v, 0, 0, n + 1);
            update(r, -v, 0, 0, n + 1);
        } else {
            int i;
            cin >> i;
            cout << get_sum(0, i + 1, 0, 0, n + 1) << '\n';
        }
    }
    return 0;
}
