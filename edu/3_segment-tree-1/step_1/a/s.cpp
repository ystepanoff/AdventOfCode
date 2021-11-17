#include <bits/stdc++.h>
using namespace std;

struct segtree {
    vector<long long> t;
    int size;

    void init(int n) {
        size = 1;
        while (size < n)
            size <<= 1;
        t.assign(size << 1, 0);
    }

    segtree(vector<int> &a) {
        init(a.size());
        build(a, 0, 0, size);
    }

    void build(vector<int> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] = lx < a.size() ? a[lx] : 0;
        } else {
            int m = (lx + rx) >> 1;
            build(a, (x << 1) + 1, lx, m);
            build(a, (x << 1) + 2, m, rx);
            t[x] = t[(x << 1) + 1] + t[(x << 1) + 2];
        }
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] = v;
            return;
        }
        int m = (lx + rx) >> 1;
        if (i < m)
            set(i, v, (x << 1) + 1, lx, m);
        else
            set(i, v, (x << 1) + 2, m, rx);
        t[x] = t[(x << 1) + 1] + t[(x << 1) + 2];
    }

    long long sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }

    long long sum(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx)
            return 0;
        if (lx >= l && rx <= r)
            return t[x];
        int m = (lx + rx) >> 1;
        return sum(l, r, (x << 1) + 1, lx, m) + sum(l, r, (x << 1) + 2, m, rx);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    segtree st(a);
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 1) {
            st.set(y, z);
        } else {
            cout << st.sum(y, z) << '\n';
        }
    }
    return 0;
}
