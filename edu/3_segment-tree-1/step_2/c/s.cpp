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

int first_ge(int v, int x, int lx, int rx) {
    if (rx - lx == 1)
        return t[x] >= v ? lx : -1;
    int m = (lx + rx) >> 1;
    if (t[(x << 1) + 1] >= v)
        return first_ge(v, (x << 1) + 1, lx, m);
    else
        return first_ge(v, (x << 1) + 2, m, rx);
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
        int x;
        cin >> x;
        if (x == 1) {
            int i, v;
            cin >> i >> v;
            update(i, v, 0, 0, n);
        } else {
            int k;
            cin >> k;
            cout << first_ge(k, 0, 0, n) << '\n';
        }
    }
    return 0;
}
