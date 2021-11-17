#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        /* k - 1 = n * (n + 1) / 2
         * n * n + n - (2*k - 2) = 0
         * (n + 1/2)^2 - (2*k - 7/4) = 0
         * n + 1/2 = +- sqrt(8*k - 7) / 2
         */
        double s = sqrt(8.0 * k - 7);
        if (s - (int)s < 1e-8)
            cout << "1 ";
        else
            cout << "0 ";
    }
    cout << '\n';
    return 0;
}
