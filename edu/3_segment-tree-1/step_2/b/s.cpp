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
    t[x] = t[(x << 1) + 1] + t[(x << 1) + 2];
}

void update(int i, int x, int lx, int rx) {
    if (rx - lx == 1) {
        t[x] = 1 - t[x];
        return;
    }
    int m = (lx + rx) >> 1;
    if (i < m)
        update(i, (x << 1) + 1, lx, m);
    else
        update(i, (x << 1) + 2, m, rx);
    t[x] = t[(x << 1) + 1] + t[(x << 1) + 2];
}

int kth_one(int k, int x, int lx, int rx) {
    if (rx - lx == 1)
        return k == 1 ? lx : -1;
    int m = (lx + rx) >> 1;
    if (t[(x << 1) + 1] >= k)
        return kth_one(k, (x << 1) + 1, lx, m);
    else
        return kth_one(k - t[(x << 1) + 1], (x << 1) + 2, m, rx);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    t.assign(n << 2, 0);
    build(a, 0, 0, n);
    while (m--) {
        int x, k;
        cin >> x >> k;
        if (x == 1) {
            update(k, 0, 0, n);
        } else {
            cout << kth_one(k + 1, 0, 0, n) << '\n';
        }
    }
    return 0;
}
