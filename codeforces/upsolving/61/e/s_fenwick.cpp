#include <bits/stdc++.h>
using namespace std;

vector<int> t;

void update(int i, int v) {
    for (; i < t.size(); i += i & -i)
        t[i] += v;
}

int sum(int i) {
    int s = 0;
    for (; i > 0; i -= i & -i)
        s += t[i];
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b(n), c(n);
    iota(b.begin(), b.end(), 0);
    sort(b.begin(), b.end(), [&](int i, int j) {
        return a[i] < a[j];
    });
    c[b[0]] = 1;
    for (int i = 1; i < n; i++)
        c[b[i]] = c[b[i - 1]] + (int)(a[b[i]] != a[b[i - 1]]);
    vector<long long> lt(n, 0), gt(n, 0);
    t.assign(n + 1, 0);
    for (int i = 0; i < n; i++) {
        update(c[i], 1);
        gt[i] = sum(n) - sum(c[i]);
    }
    t.assign(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        update(c[i], 1);
        lt[i] = sum(c[i] - 1);
    }
    long long total = 0;
    for (int i = 0; i < n; i++)
        total += lt[i] * gt[i];
    cout << total << '\n';
    return 0;
}
