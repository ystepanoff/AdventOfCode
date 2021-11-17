#include <bits/stdc++.h>
using namespace std;

vector<int> t;

void build(vector<int> &a, int lv, int x, int lx, int rx) {
    if (rx - lx == 1) {
        t[x] = a[lx];
        return;
    }
    int m = (lx + rx) >> 1;
    build(a, lv + 1, (x << 1) + 1, lx, m);
    build(a, lv + 1, (x << 1) + 2, m, rx);
    if (lv & 1)
        t[x] = t[(x << 1) + 1] ^ t[(x << 1) + 2];
    else
        t[x] = t[(x << 1) + 1] | t[(x << 1) + 2];
}

void update(int i, int v, int lv, int x, int lx, int rx) {
    if (rx - lx == 1) {
        t[x] = v;
        return;
    }
    int m = (lx + rx) >> 1;
    if (i < m)
        update(i, v, lv + 1, (x << 1) + 1, lx, m);
    else
        update(i, v, lv + 1, (x << 1) + 2, m, rx);
    if (lv & 1)
        t[x] = t[(x << 1) + 1] ^ t[(x << 1) + 2];
    else
        t[x] = t[(x << 1) + 1] | t[(x << 1) + 2];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int lv = n & 1 ? 0 : 1;
    n = (1 << n);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    t.assign(n << 2, 0);
    build(a, lv, 0, 0, n);
    while (m--) {
        int p, b;
        cin >> p >> b;
        update(p - 1, b, lv, 0, 0, n);
        cout << t[0] << '\n';
    }
    return 0;
}
