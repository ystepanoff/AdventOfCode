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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        bool yes = true;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) yes &= a[i] + 1 == b[i];
        }
        cout << (yes ? "YES" : "NO") << '\n';
    }
    return 0;
}
