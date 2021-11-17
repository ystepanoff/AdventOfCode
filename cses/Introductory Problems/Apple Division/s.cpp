#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; 
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long best = -1;
    for (int mask = 0; mask < (1 << n); mask++) {
        long long s = 0, t = 0;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i)) s += a[i]; else t += a[i];
        if (best == -1 || abs(s - t) < best)
            best = abs(s - t);
    }
    cout << best << '\n';
    return 0;
}
