#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long q;
    cin >> q;
    auto z = [](long long m) {
        long long r = 0;
        for (; m > 0; m /= 5)
            r += m / 5;
        return r;
    };
    long long l = 0, r = 1e18;
    while (r - l > 1) {
        long long m = (l + r) >> 1;
        if (z(m) >= q) r = m; else l = m;
    }
    if (z(r) == q) {
        cout << r << '\n';
    } else {
        cout << "No solution\n";
    }
    return 0;
}
