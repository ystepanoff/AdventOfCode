#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m, k;
        cin >> n >> m >> k;
        // first row + last column: (m - 1) + (n - 1) * m = m - 1 + n * m - m = n * m - 1
        // first column + last row: (n - 1) + (m - 1) * n = n - 1 + m * n - n = m * n - 1
        cout << (m * n - 1 == k ? "YES" : "NO") << '\n';
    }
    return 0;
}
