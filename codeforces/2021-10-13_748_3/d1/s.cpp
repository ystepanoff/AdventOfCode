#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool same = true;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i - 1]) {
                same = false;
                break;
            }
        }
        if (same) {
            cout << "-1\n";
        } else {
            int mn = *min_element(a.begin(), a.end());
            int g = 0;
            for (int i = 0; i < n; i++) {
                g = __gcd(g, a[i] - mn);
            }
            cout << g << '\n';
        }
    }
    return 0;
}
