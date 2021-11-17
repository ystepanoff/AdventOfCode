#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

long long powmod(long long a, long long b, long long m) {
    long long r = 1;
    while (b > 0) {
        if (b & 1)
            r = (r * a) % mod, b--;
        a = (a * a) % mod, b >>= 1;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int m = s.size();
    if (m >= n) {
        cout << (int)(m == n)<< '\n';
        return 0;
    }
    int k = n - m;
    long long r = 0;
    for (int i = 0; i <= k; i++)
        r = (r + powmod(26, k, mod)) % mod;
    cout << r << '\n';
    return 0;
}
