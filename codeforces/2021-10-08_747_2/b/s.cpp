#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        long long n, k;
        cin >> n >> k;
        long long r = 0;
        long long p = 1;
        for (int i = 0; i < 31; i++) {
            if (k & (1 << i)) r = (r + p) % mod;
            p = (p * n) % mod;
        }
        cout << r << '\n';
    }
    return 0;
}
