#include <bits/stdc++.h>
using namespace std;

typedef tuple<long long,long long,long long> triple;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        long long n;
        cin >> n;
        long long total = 0;
        for (long long a = 1; a * a <= 3 * n; a += 2) {
            long long b = (a * a - 1) >> 1;
            long long c = b + 1;
            if (a <= b && b <= c && c <= n) total++;
        }
        cout << total << '\n';
    }
    return 0;
}
