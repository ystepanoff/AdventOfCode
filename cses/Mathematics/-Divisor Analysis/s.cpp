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
    int n;
    cin >> n;
    vector<long long> p(n), pw(n);
    for (int i = 0; i < n; i++)
        cin >> p[i] >> pw[i];
    long long x = 1, y = 1, z = 1, t = 1;
    for (int i = 0; i < n; i++) {
        x = (x * (pw[i] + 1)) % mod;
        y = (y * (powmod(p[i], pw[i] + 1, mod) - 1)) % mod;
        y = (y * powmod(p[i] - 1, mod - 2, mod)) % mod;
        z = (z * powmod(p[i], pw[i], mod)) % mod;
    }
    z = powmod(z, (x * powmod(2, mod - 2, mod)) % mod, mod);
    cout << x << ' ' << y << ' ' << z << '\n';
    return 0;
}
