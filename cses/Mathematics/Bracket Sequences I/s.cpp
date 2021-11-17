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
    long long n;
    cin >> n;
    if (n & 1) {
        cout << "0\n";
        return 0;
    }
    n >>= 1;
    long long r = 1;
    for (long long i = 2; i <= 2 * n; i++)
        r = (r * i) % mod;
    for (long long i = 2; i <= n; i++) {
        r = (r * powmod(i, mod - 2, mod)) % mod;
        r = (r * powmod(i, mod - 2, mod)) % mod;
    }
    r = (r * powmod(n + 1, mod - 2, mod)) % mod;
    cout << r << '\n';
    return 0;
}
