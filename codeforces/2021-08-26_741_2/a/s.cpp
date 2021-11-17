#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        long long l, r;
        cin >> l >> r;
        long long best = 0;
        for (long long a = r - 10; a <= r; a++) {
            for (long long b = (r / 2) - 10; b <= (r / 2) + 10; b++)
                if (l <= b && b <= a && a <= r)
                    best = max(best, a % b);
            for (long long b = l; b <= l + 10; b++)
                if (l <= b && b <= a && a <= r)
                    best = max(best, a % b);
        }
        cout << best << '\n';
    }
    return 0;
}
