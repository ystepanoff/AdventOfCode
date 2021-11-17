#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &a, int l, int r, int m) {
    vector<int> c;
    int i = l, j = m + 1;
    int inv = 0;
    while (i <= m && j <= r)
        if (a[i] <= a[j]) {
            c.push_back(a[i++]);
        } else {
            c.push_back(a[j++]);
            inv += m - i + 1;
        }
    while (i <= m)
        c.push_back(a[i++]);
    while (j <= r)
        c.push_back(a[j++]);
    for (int i = l; i <= r; i++)
        a[i] = c[i-l];
    return inv;
}

int inv_count(vector<int> &a, int l, int r) {
    int inv = 0;
    if (r - l > 0) {
        int m = (l + r) >> 1;
        inv += inv_count(a, l, m);
        inv += inv_count(a, m + 1, r);
        inv += merge(a, l, r, m);
    }
    return inv;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int best = 0, besti = 1;
    for (int i = 1; i <= k; i++) {
        vector<int> a(n);
        for (int j = 0; j < n; j++)
            cin >> a[j];
        int inv = inv_count(a, 0, n - 1);
        if (inv > best) {
            best = inv;
            besti = i;
        }
    }
    cout << besti << '\n';
    return 0;
}
