#include <bits/stdc++.h>
using namespace std;

vector<long long> t;

void build(vector<int> &a, int x, int lx, int rx) {
    if (rx - lx == 1) {
        t[x] = a[lx];
        return;
    }
    int m = (lx + rx) >> 1;
    build(a, (x << 1) + 1, lx, m);
    build(a, (x << 1) + 2, m, rx);
    t[x] = t[(x << 1) + 1] + t[(x << 1) + 2];
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
    t[x] = t[(x << 1) + 1] + t[(x << 1) + 2];
}

long long get_sum(int l, int r, int x, int lx, int rx) {
    if (lx >= r || l >= rx)
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i & 1)
            a[i] = -a[i];
    }
    t.assign(n << 2, 0);
    build(a, 0, 0, n);
    int m;
    cin >> m;
    while (m--) {
        int x, i, j;
        cin >> x >> i >> j;
        if (x == 0) {
            if ((i - 1) & 1)
                update(i - 1, -j, 0, 0, n);
            else
                update(i - 1, j, 0, 0, n);
        } else {
            long long s = get_sum(i - 1, j, 0, 0, n);
            cout << ((i - 1) & 1 ? -s : s) << '\n';
        }
    }
    return 0;
}
