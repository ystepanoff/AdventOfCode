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
    int m = n << 1;
    t.assign(m << 2, 0);
    vector<int> a(m), p(n, -1), c(n, 0);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        a[i]--;
        if (p[a[i]] == -1) {
            update(i, 1, 0, 0, m);
            p[a[i]] = i;
        } else {
            update(p[a[i]], 0, 0, 0, m);
            c[a[i]] = get_sum(p[a[i]], i, 0, 0, m);
        }
    }
    fill(t.begin(), t.end(), 0);
    fill(p.begin(), p.end(), -1);
    reverse(a.begin(), a.end());
    for (int i = 0; i < m; i++) {
        if (p[a[i]] == -1) {
            update(i, 1, 0, 0, m);
            p[a[i]] = i;
        } else {
            update(p[a[i]], 0, 0, 0, m);
            c[a[i]] += get_sum(p[a[i]], i, 0, 0, m);
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
