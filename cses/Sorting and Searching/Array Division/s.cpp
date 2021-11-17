#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    auto can = [n, k, &a](long long s) {
        long long curr = 0;
        int total = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] > s)
                return false;
            curr += a[i];
            if (curr > s) {
                curr = a[i];
                total++;
            }
        }
        return total <= k;
    };
    long long l = 0, r = 1e18;
    while (r - l > 1) {
        long long m = (l + r) / 2;
        if (can(m)) r = m; else l = m;
    }
    cout << r << '\n';
    return 0;
}
