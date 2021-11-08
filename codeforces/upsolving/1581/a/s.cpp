#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long mod = 1e9 + 7;
    long long i2 = 500000004;
    long long N = 2 * 100100;
    vector<long long> fact(N);
    fact[1] = 1;
    for (int i = 2; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        cout << (fact[n << 1] * i2) % mod << '\n';
    }
    return 0;
}
