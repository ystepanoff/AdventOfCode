#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n, 0);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                a[i] = a[i] * 10 + c - '0';
            }
        }
    }
    auto can = [&](long long x) {
        long long total = 0;
        for (long long y : a) {
            total += y / x;
        }
        return total >= k;
    };
    long long l = 0, r = 1e18;
    while (r - l > 1) {
        long long m = (l + r) >> 1;
        if (can(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << fixed << setprecision(2) << (l >= 1 ? l * 0.01 : 0) << '\n';
    return 0;
}
