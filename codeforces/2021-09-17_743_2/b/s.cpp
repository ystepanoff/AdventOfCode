#include <bits/stdc++.h>
using namespace std;

void update(vector<long long> &t, int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1) {
        t[x] = v;
        return;
    }
    int m = (lx + rx) >> 1;
    if (i < m) 
        update(t, i, v, (x << 1) + 1, lx, m);
    else
        update(t, i, v, (x << 1) + 2, m, rx);
    t[x] = min(t[(x << 1) + 1], t[(x << 1) + 2]);
}

long long query(vector<long long> &t, int l, int r, int x, int lx, int rx) {
    if (l >= rx || lx >= r) return INT_MAX;
    if (lx >= l && rx <= r) return t[x];
    int m = (lx + rx) >> 1;
    return min(query(t, l, r, (x << 1) + 1, lx, m),
               query(t, l, r, (x << 1) + 2, m, rx));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        int m = (n << 1) + 1;
        vector<long long> ta(m << 2, INT_MAX);
        vector<long long> tb(m << 2, INT_MAX);
        for (int i = 0; i < n; i++) {
            update(ta, a[i], i, 0, 0, m);
            update(tb, b[i], i, 0, 0, m);
        }
        long long best = INT_MAX;
        for (int i = 0; i < n; i++) {
            best = min(best, i + query(tb, a[i], m, 0, 0, m));
            best = min(best, i + query(ta, 0, b[i], 0, 0, m));
        }
        cout << best << '\n';
    }
    return 0;
}
