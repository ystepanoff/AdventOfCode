#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    int k;
    cin >> n >> k;
    vector<long long> p(k);
    for (int i = 0; i < k; i++)
        cin >> p[i];
    long long r = n;
    for (int mask = 0; mask < (1 << k); mask++) {
        long long s = -1, t = n;
        for (int i = 0; i < k; i++)
            if (mask & (1 << i))
                s = -s, t /= p[i];
        r += s * t;
    }
    cout << r << '\n';
    return 0;
}
