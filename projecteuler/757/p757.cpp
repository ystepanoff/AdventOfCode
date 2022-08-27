#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n = 1e14;
    long long m = (long long)(sqrt(sqrt(n * 1.0)));
    vector<long long> all;
    for (long long x = 1; x <= m; x++) {
        for (long long y = x; ; y++) {
            long long z = x * (x + 1) * y * (y + 1);
            if (z > n) break;
            all.push_back(z);
        }
    }
    sort(all.begin(), all.end());
    int total = 1;
    for (int i = 1; i < all.size(); i++) {
        if (all[i] != all[i - 1]) total++;
    }
    cout << total << '\n';
    return 0;
}
