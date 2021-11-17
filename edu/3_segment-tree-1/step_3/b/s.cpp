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

int kth_one(int k, int x, int lx, int rx) {
    if (rx - lx == 1)
        return k == 1 ? lx : -1;
    int m = (lx + rx) >> 1;
    if (t[(x << 1) + 2] >= k)
        return kth_one(k, (x << 1) + 2, m, rx);
    return kth_one(k - t[(x << 1) + 2], (x << 1) + 1, lx, m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n, 1), p(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    t.assign(n << 2, 0);
    build(b, 0, 0, n);
    for (int i = n - 1; i >= 0; i--) {
        int k = kth_one(a[i] + 1, 0, 0, n);
        update(k, 0, 0, 0, n);
        p[i] = k + 1;
    }
    for (int i = 0; i < n; i++) {
        cout << p[i];
        if (i < n - 1)
            cout << ' ';
    }
    cout << '\n';
    return 0;
}
