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
        vector<int> odd(100100, 0), even(100100, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i & 1) odd[a[i]]++; else even[a[i]]++;
        }
        bool ok = true;
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            if (i & 1) odd[a[i]]--; else even[a[i]]--;
        }
        for (int x : odd) ok &= x == 0;
        for (int x : even) ok &= x == 0;
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
