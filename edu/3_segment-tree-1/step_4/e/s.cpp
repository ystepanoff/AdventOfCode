#include <bits/stdc++.h>
using namespace std;

vector<int> t;

void update(int n, int i, int v) {
    int lx = 0, rx = n;
    int x = 0;
    vector<int> nodes;
    while (rx - lx > 1) {
        nodes.push_back(x);
        int m = (lx + rx) >> 1;
        if (i < m) {
            x = (x << 1) + 1;
            rx = m;
        } else {
            x = (x << 1) + 2;
            lx = m;
        }
    }
    t[x] = v;
    for (int x : vector<int>(nodes.rbegin(), nodes.rend()))
        t[x] = min(t[(x << 1) + 1], t[(x << 1) + 2]);
}

int count(int l, int r, int p, int x, int lx, int rx) {
    if (lx >= r || l >= rx || t[x] > p) return 0;
    if (rx - lx == 1) {
        t[x] = INT_MAX;
        return 1;
    }
    int m = (lx + rx) >> 1;
    int c1 = count(l, r, p, (x << 1) + 1, lx, m); 
    int c2 = count(l, r, p, (x << 1) + 2, m, rx);
    t[x] = min(t[(x << 1) + 1], t[(x << 1) + 2]);
    return c1 + c2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    t.assign(n << 2, INT_MAX);
    while (m--) {
        int x;
        cin >> x;
        if (x == 1) {
            int i, h;
            cin >> i >> h;
            update(n, i, h);
        } else {
            int l, r, p;
            cin >> l >> r >> p;
            cout << count(l, r, p, 0, 0, n) << '\n';
        }
    }
    return 0;
}
