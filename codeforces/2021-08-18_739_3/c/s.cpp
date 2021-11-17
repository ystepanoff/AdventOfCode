#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int k;
        cin >> k;
        int m;
        for (m = 1; ; m++)
            if ((m - 1) * (m - 1) + 1 <= k && k <= m * m) {
                break;
            }
        int x, y;
        if (k - (m - 1) * (m - 1) <= m) {
            x = k - (m - 1) * (m - 1);
            y = m;
        } else {
            x = m;
            y = m * m - k + 1;
        }
        cout << x << ' ' << y << '\n';
    }
    return 0;
}
