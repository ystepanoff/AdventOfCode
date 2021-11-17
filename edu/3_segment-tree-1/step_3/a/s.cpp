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

int sum(int l, int r, int x, int lx, int rx) {
    if (lx >= r || l >= rx)
        return 0;
    if (lx >= l && rx <= r)
        return t[x];
    int m = (lx + rx) >> 1;
    return sum(l, r, (x << 1) + 1, lx, m) +
           sum(l, r, (x << 1) + 2, m, rx);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    t.assign(n << 2, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cout << sum(x - 1, n, 0, 0, n);
        if (i < n - 1)
            cout << ' ';
        update(x - 1, 1, 0, 0, n);
    }
    cout << '\n';
    return 0;
}
