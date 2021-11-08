#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        long long n;
        cin >> n;
        long long total = n * (n - 1) * (n - 2) / 6;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }
        vector<long long> ac(n + 1, 0), bc(n + 1, 0);
        for (int i = 0; i < n; i++) {
            ac[a[i]]++;
            bc[b[i]]++;
        }
        for (int i = 0; i < n; i++) {
            total -= (ac[a[i]] - 1) * (bc[b[i]] - 1);
        }
        cout << total << '\n';
    }
    return 0;
}
