#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n, t;
    cin >> n >> t;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    auto can = [t, &a](long long T) {
        long long k = 0;
        for (long long x : a)
            k += T / x;
        return k >= t;
    };
    long long l = 0, r = *min_element(a.begin(), a.end()) * t;
    while (r - l > 1) {
        long long m = (l + r) / 2;
        if (can(m))
            r = m;
        else
            l = m;
    }
    cout << r << '\n';
    return 0;
}
