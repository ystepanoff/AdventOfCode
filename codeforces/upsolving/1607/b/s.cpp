#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long d[4] = { 0, -1, 1, 4 };
    int tt;
    cin >> tt;
    while (tt--) {
        long long x, n;
        cin >> x >> n;
        long long d[4] = { 0, -n, 1, n + 1 };
        if (x & 1) x -= d[n % 4]; else x += d[n % 4];
        cout << x  << '\n';
    }
    return 0;
}
