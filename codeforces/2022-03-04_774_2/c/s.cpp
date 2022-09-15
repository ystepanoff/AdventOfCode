#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<long long> fact;
    for (long long i = 1, f = 1; f < 1e12; f *= i, i++) fact.push_back(f);
    int _t;
    cin >> _t;
    while (_t--) {
        long long n;
        cin >> n;
        int best = __builtin_popcountll(n);
        for (int mask = 0; mask < (1 << fact.size()); mask++) {
            long long s = 0;
            int c = 0;
            for (int i = 0; i < fact.size(); i++) {
                if (mask & (1 << i)) {
                    s += fact[i];
                    c++;
                }
            }
            if (n >= s) best = min(best, c + __builtin_popcountll(n - s));
        }
        cout << best << '\n';
    }
    return 0;
}
