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
    int n;
    cin >> n;
    int m = n << 1;
    t.resize(m << 2, 0);
    vector<int> p(n, -1), c(n, 0);
    for (int i = 0; i < m; i++) {
        int v;
        cin >> v;
        v--;
        if (p[v] != -1) {
            c[v] = get_sum(p[v], i + 1, 0, 0, m);
            update(p[v], 1, 0, 0, m);
        } else {
            p[v] = i;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << c[i];
        if (i < n - 1)
            cout << ' ';
    }
    cout << '\n';
    return 0;
}
