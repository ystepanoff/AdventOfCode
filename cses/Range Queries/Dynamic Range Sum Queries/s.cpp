#include <bits/stdc++.h>
using namespace std;

vector<long long> t;
int n, q;

void update(int i, long long x) {
    for (; i <= n; i += i & -i)
        t[i] += x;
}

long long sum(int i) {
    long long r = 0;
    for (; i > 0; i -= i & -i)
        r += t[i];
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    vector<int> a(n + 1);
    t.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(i, a[i]);
    }
    while (q--) {
        int x, l, r;
        cin >> x >> l >> r;
        if (x == 1) {
            update(l, r - a[l]);
            a[l] = r;
        } else {
            cout << sum(r) - sum(l - 1) << '\n';
        }
    }
    return 0;
}
