#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<long long> a(k), t(k);
        for (int i = 0; i < k; i++) {
            cin >> a[i];
            a[i]--;
        }
        for (int i = 0; i < k; i++) {
            cin >> t[i];
        }
        vector<long long> b(n, INT_MAX), c(n, INT_MAX);
        for (int i = 0; i < k; i++) {
            b[a[i]] = t[i];
            c[a[i]] = t[i];
        }
        for (int i = 1; i < n; i++) {
            b[i] = min(b[i], b[i - 1] + 1);
        }
        c[n - 1] = min(c[n - 1], b[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            c[i] = min(c[i], c[i + 1] + 1);
            c[i] = min(c[i], b[i]);
        }
        for (int i = 0; i < n; i++) {
            cout << c[i];
            if (i < n - 1) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
