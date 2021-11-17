#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7;
long long limit = 1e6 + 1;
vector<long long> phi(limit);

long long powmod(long long a, long long b) {
    long long r = 1;
    while (b > 0) {
        if (b & 1) r = (r * a) % mod, a--;
        a = (a * a) % mod, b >>= 1;
    }
    return r;
}

auto op = [&](auto &x, auto &y) {
    long long m = x.first;
    long long n = y.first;
    long long r = (x.second * y.second) % mod;
    long long g = gcd(m, n);
    r = (r * g) % mod;
    r = (r * powmod(phi[g], mod - 2)) % mod;
    return make_pair(
};

vector<pair<long long, long long>> t;

void build(int x, int lx, int rx) {
    if (rx - lx == 1) {
        t[x] = { lx, phi[lx] };
        return;
    }
    int m = (lx + rx) >> 1;
    build((x << 1) + 1, lx, m);
    build((x << 1) + 2, m, rx);
    t[x] = op(t[(x << 1) + 1], t[(x << 1) + 2]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    iota(phi.begin(), phi.end(), 0);
    for (int i = 2; i < limit; i++) {
        if (phi[i] == i) {
            for (int j = i; j < limit; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
    cout << phi[10] << '\n';
    cout << op(10, 20) << '\n';
    return 0;
}
