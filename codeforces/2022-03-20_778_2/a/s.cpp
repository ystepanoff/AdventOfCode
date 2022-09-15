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
        int best = a[0] + a[1];
        for (int i = 0; i + 1 < n; i++)
            best = max(best, a[i] + a[i + 1]);
        for (int l = 0; l < n; l++) {
            for (int r = l + 1; r < n; r++) {
                if (l > 0) best = max(best, a[l - 1] + a[r]);
                if (r + 1 < n) best = max(best, a[l] + a[r + 1]);
            }
        }
        cout << best << '\n';
    }
    return 0;
}
