#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long mod = 1e9 + 7;
    int tt;
    cin >> tt;
    while (tt--) {
        long long n;
        cin >> n;
        long long l1 = 1, l2 = 1;
        long long total = 0;
        for (long long y = 2; l1 <= n; y++) {
            l2 = l2 / __gcd(l2, y) * y;
            total = (total + y * (n / l1 - n / l2)) % mod;
            l1 = l1 / __gcd(l1, y) * y;
        }
        cout << total << '\n';
    }
    return 0;
}
