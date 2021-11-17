#include <bits/stdc++.h>
using namespace std;

/**
 * n = (2 * a + (p - 1)) * p / 2
 * 2 * a = (2 * n) / p - (p - 1)
 * a = n / p - (p - 1) / 2
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;
    for (long long p = 2 * (long long)sqrt(n * 1.0); p >= 1; p--)
        if (!((2 * n) % p) && ((2 * n) / p - (p - 1)) % 2  == 0 && (n / p - (p - 1) / 2) > 0) {
            cout << (n / p - (p - 1) / 2) << ' ' << p << '\n';
            break;
        }
    return 0;
}
