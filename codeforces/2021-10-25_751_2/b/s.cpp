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
        map<int,vector<int>> mp;
        int maxj = 0;
        for (int j = 0; ; j++) {
            mp[j] = a;
            maxj = j;
            vector<int> cnt(2010, 0);
            for (int x : a) cnt[x]++;
            vector<int> b(n);
            for (int i = 0; i < n; i++) {
                b[i] = cnt[a[i]];
            }
            bool same = true;
            for (int i = 0; i < n; i++) {
                same &= a[i] == b[i];
            }
            if (same) {
                break;
            }
            a = b;
        }
        int q;
        cin >> q;
        while (q--) {
            int x, k;
            cin >> x >> k;
            k = min(k, maxj);
            cout << mp[k][x - 1] << '\n';
        }
    }
    return 0;
}
