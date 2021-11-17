#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    while (cin >> n) {
        long long m = 2 * n + 1;
        if (n & 1)
            m = -m;
        cout << (m - 1) / 4 << '\n';
    }
    return 0;
}
