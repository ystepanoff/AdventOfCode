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
        int mn = *min_element(a.begin(), a.end());
        int mx = *max_element(a.begin(), a.end());
        int best = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i] == mn && a[j] == mx) {
                    if (i >= j) {
                        best = min(best, min(i + 1, n - j));
                        best = min(best, n - i + j + 1);
                    } else {
                        best = min(best, min(j + 1, n - i));
                        best = min(best, n - j + i + 1);
                    }
                }
            }
        }
        cout << best << '\n';
    }
    return 0;
}
