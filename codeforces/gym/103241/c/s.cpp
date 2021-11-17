#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        if (n == m) {
            cout << n << " 3\n";
        } else {
            cout << max(n, m) << " 1\n";
        }
    }
    return 0;
}
