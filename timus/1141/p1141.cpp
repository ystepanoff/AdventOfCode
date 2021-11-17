#include <bits/stdc++.h>
using namespace std;

int gcdex(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int x1, y1;
    int g = gcdex(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

int mod_inverse(int a, int m) {
    int b, k;
    int g = gcdex(a, m, b, k);
    if (g != 1)
        return -1;
    return (b + m) % m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int e, n, c;
        cin >> e >> n >> c;
        for (int p = 2; p * p <= n; p++)
            if (!(n % p)) {
                int phi = (p - 1) * (n / p - 1);
                int d = mod_inverse(e, phi);
                int r = 1;
                while (d > 0) {
                    if (d & 1)
                        r = (r * c) % n, d--;
                    c = (c * c) % n, d >>= 1;
                }
                cout << r << '\n';
                break;
            }
    }
    return 0;
}
