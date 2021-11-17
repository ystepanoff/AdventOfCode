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
        sort(a.begin(), a.end());
        int best = a[0];
        for (int i = 1; i < n; i++) {
            best = max(best, a[i] - a[i - 1]);
        }
        cout << best << '\n';
    }
    return 0;
}
