#include <bits/stdc++.h>
using namespace std;

typedef tuple<int,int,int,int> m22;
int mod = 1;

auto op(m22 a, m22 b) {
    int a11, a12, a21, a22, b11, b12, b21, b22;
    tie(a11, a12, a21, a22) = a;
    tie(b11, b12, b21, b22) = b;
    return make_tuple((a11 * b11 + a12 * b21) % mod,
                      (a11 * b12 + a12 * b22) % mod,
                      (a21 * b11 + a22 * b21) % mod,
                      (a21 * b12 + a22 * b22) % mod);
}

vector<m22> t;

void build(vector<m22> &a, int x, int lx, int rx) {
    if (rx - lx == 1) {
        t[x] = a[lx];
        return;
    }
    int m = (lx + rx) >> 1;
    build(a, (x << 1) + 1, lx, m);
    build(a, (x << 1) + 2, m, rx);
    t[x] = op(t[(x << 1) + 1], t[(x << 1) + 2]);
}

m22 get_prod(int l, int r, int x, int lx, int rx) {
    if (lx >= r || l >= rx)
        return { 1, 0, 0, 1 };
    if (lx >= l && rx <= r)
        return t[x];
    int m = (lx + rx) >> 1;
    return op(get_prod(l, r, (x << 1) + 1, lx, m),
              get_prod(l, r, (x << 1) + 2, m, rx));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> mod >> n >> m;
    vector<m22> a(n);
    for (int i = 0; i < n; i++) {
        int a11, a12, a21, a22;
        cin >> a11 >> a12 >> a21 >> a22;
        a[i] = { a11, a12, a21, a22 };
    }
    t.assign(n << 2, { 1, 0, 0, 1 });
    build(a, 0, 0, n);
    while (m--) {
        int i, j;
        cin >> i >> j;
        int a11, a12, a21, a22;
        tie(a11, a12, a21, a22)  = get_prod(i - 1, j, 0, 0, n);
        cout << a11 << ' ' << a12 << '\n';
        cout << a21 << ' ' << a22 << '\n';
        cout << '\n';
    }
    return 0;
}
