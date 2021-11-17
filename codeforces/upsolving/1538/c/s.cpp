#include <bits/stdc++.h>
using namespace std;

long long count(vector<int> &a, int x) {
    long long total = 0;
    for (int i = 0; i < a.size(); i++) {
        // a[i] + a[j] <= x
        // a[j] <= x - a[i]
        // i < j
        int l = i, r = a.size();
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (a[m] <= x - a[i]) l = m; else r = m;
        }
        total += r - i + 1;
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        cout << count(a, r) - count(a, l - 1) << '\n';
    }
    return 0;
}
