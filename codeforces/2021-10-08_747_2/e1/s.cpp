#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7;

long long powmod(long long a, long long b) {
    long long r = 1;
    while (b > 0) {
        if (b & 1) r = (r * a) % mod, b--;
        a = (a * a) % mod, b >>= 1;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;
    long long p2 = 1;
    for (int i = 0; i <= n; i++) p2 *= 2;
    cout << (6 * powmod(2, p2 - 4)) % mod << '\n';
    return 0;
}
