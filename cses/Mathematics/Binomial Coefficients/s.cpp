#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

long long powmod(long long a, long long b, long long m) {
    long long r = 1;
    while (b > 0) {
        if (b & 1)
            r = (r * a) % m, b--;
        a = (a * a) % m, b >>= 1;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<long long> f(1e6 + 1, 1);
    for (int i = 2; i <= 1e6; i++)
        f[i] = (i * f[i - 1]) % mod;
    int tt;
    cin >> tt;
    while (tt--) {
        long long a, b;
        cin >> a >> b;
        long long x = f[a];
        long long y = (f[b] * f[a - b]) % mod;
        cout << (x * powmod(y, mod - 2, mod)) % mod << '\n';
    }
    return 0;
}
