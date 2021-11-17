#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<bool> prime(1000, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i < 1000; i++)
        if (prime[i])
            for (int j = 2; j * i < 1000; j++)
                prime[j * i] = false;
    int n;
    cin >> n;
    vector<long long> d(1000, 0), f(1000, 0);
    for (int i = 100; i < 1000; i++)
        if (prime[i])
            d[i] = 1;
    for (int i = 4; i <= n; i++) {
        fill(f.begin(), f.end(), 0);
        for (int a = 100; a < 1000; a++)
            if (prime[a])
                for (int b = 1; b < 10; b++) {
                    int c = (a % 100) * 10 + b;
                    if (prime[c]) (f[c] += d[a]) %= mod;
                }
        d = f;
    }
    long long s = 0;
    for (int i = 100; i < 1000; i++)
        (s += d[i]) %= mod;
    cout << s << '\n';
    return 0;
}
