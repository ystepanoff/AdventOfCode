#include <bits/stdc++.h>
using namespace std;

struct node {
    int n, o, c;
};

node op(node a, node b) {
    int k = min(a.o, b.c);
    return { a.n + b.n + k, a.o + b.o - k, a.c + b.c - k };
}

vector<node> t;

void build(string &s, int x, int lx, int rx) {
    if (rx - lx == 1) {
        node v = { 0, 0, 0 };
        if (s[lx] == '(') v.o = 1; else v.c = 1;
        t[x] = v;
        return;
    }
    int m = (lx + rx) >> 1;
    build(s, (x << 1) + 1, lx, m);
    build(s, (x << 1) + 2, m, rx);
    t[x] = op(t[(x << 1) + 1], t[(x << 1) + 2]);
}

node query(int l, int r, int x, int lx, int rx) {
    if (l >= rx || lx >= r) return { 0, 0, 0 };
    if (lx >= l && rx <= r) return t[x];
    int m = (lx + rx) >> 1;
    return op(query(l, r, (x << 1) + 1, lx, m),
              query(l, r, (x << 1) + 2, m, rx));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    t.assign(n << 2, {0, 0, 0});
    build(s, 0, 0, n);
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        node v = query(l - 1, r, 0, 0, n);
        cout << (v.n << 1) << '\n';
    }
    return 0;
}
