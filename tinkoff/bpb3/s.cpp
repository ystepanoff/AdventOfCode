#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long k;
    cin >> k;
    vector<long long> divs;
    for (long long c = 1; c * c <= k; c++)
        if (!(k % c)) {
            divs.push_back(c);
            divs.push_back(k / c);
        }
    long long best = 1e18;
    for (long long i : divs) {
        long long j = k / i;
        best = min(best, i + j - 2);
    }
    cout << best << '\n';
    return 0;
}
