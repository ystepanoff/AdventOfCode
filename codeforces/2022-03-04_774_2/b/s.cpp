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
        sort(a.rbegin(), a.rend());
        long long sr = a[0], sb = a[n - 1] + a[n - 2];
        if (sr > sb) {
            cout << "yes\n";
            continue;
        }
        bool ok = false;
        for (int i = 1; i < n / 2; i++) {
            sr += a[i];
            sb += a[n - i - 2];
            if (sr > sb) {
                cout << "yes\n";
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << "no\n";
        }
    }
    return 0;
}
