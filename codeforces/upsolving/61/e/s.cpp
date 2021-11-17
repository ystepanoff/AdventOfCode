#include <bits/stdc++.h>
using namespace std;

vector<int> t;

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

int get_sum(int l, int r, int x, int lx, int rx) {
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
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b(n);
    iota(b.begin(), b.end(), 0);
    sort(b.begin(), b.end(), [&](int i, int j) {
        return a[i] < a[j];
    });
    vector<int> c(n);
    c[b[0]] = 0;
    for (int i = 1; i < n; i++)
        c[b[i]] = c[b[i - 1]] + (int)(a[b[i]] != a[b[i - 1]]);
    vector<long long> lt(n, 0), gt(n, 0);
    t.assign(n << 2, 0);
    for (int i = 0; i < n; i++) {
        update(c[i], 1, 0, 0, n);
        gt[i] += get_sum(c[i] + 1, n, 0, 0, n);
    }
    t.assign(n << 2, 0);
    for (int i = n - 1; i >= 0; i--) {
        update(c[i], 1, 0, 0, n);
        lt[i] += get_sum(0, c[i], 0, 0, n);
    }
    long long total = 0;
    for (int i = 0; i < n; i++)
        total += lt[i] * gt[i];
    cout << total << '\n';
    return 0;
}
