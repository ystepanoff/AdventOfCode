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
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << powmod(a, powmod(b, c, mod - 1), mod) << '\n';
    }
    return 0;
}
