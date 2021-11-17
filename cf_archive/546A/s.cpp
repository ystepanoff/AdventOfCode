#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long k, n, w;
    while (cin >> k >> n >> w) {
        long long total = 0;
        for (long long i = 1; i <= w; i++)
            total += i * k;
        total -= n;
        if (total < 0)
            total = 0;
        cout << total << "\n";
    }
    return 0;
}
