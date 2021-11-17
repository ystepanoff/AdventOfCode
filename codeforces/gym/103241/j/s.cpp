#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long x;
    cin >> n >> x;
    vector<pair<long long,long long>> tr(n);
    for (auto &p : tr)
        cin >> p.first >> p.second;
    auto can = [&](long long v) {
        long long total = 0;
        for (auto &p : tr)
            total += max(0LL, v - p.first) / p.second;
        return total >= x;
    };
    long long l = 0, r = 1e16;
    while (r - l > 1) {
        long long m = (l + r) >> 1;
        if (can(m))
            r = m;
        else
            l = m;
    }
    cout << r << '\n';
    return 0;
}
