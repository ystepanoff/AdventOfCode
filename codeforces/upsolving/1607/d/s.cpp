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
        vector<pair<int,int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].second;
        }
        string s;
        cin >> s;
        for (int i = 0; i < n; i++) {
            a[i].first = s[i] == 'B' ? 0 : 1;
        }
        sort(a.begin(), a.end());
        bool yes = true;
        for (int i = 0; i < n; i++) {
            if (a[i].first == 0) yes &= a[i].second >= i + 1;
            if (a[i].first == 1) yes &= a[i].second <= i + 1;
        }
        cout << (yes ? "YES" : "NO") << '\n';
    }
    return 0;
}
