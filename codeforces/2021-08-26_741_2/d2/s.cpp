#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, q;
        string s;
        cin >> n >> q >> s;
        vector<int> a(n + 1, 0);
        for (int i = 0; i < n; i++)
            a[i + 1] = s[i] == '+' ? 1 : -1;
        vector<int> pref(n + 1, 0);
        for (int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + (i & 1 ? 1 : -1) * a[i];
        map<int,vector<int>> mp;
        for (int i = 1; i <= n; i++)
            mp[pref[i] + pref[i - 1]].push_back(i);
        while (q--) {
            int l, r;
            cin >> l >> r;
            if (pref[r] - pref[l - 1] == 0) {
                cout << "0\n";
            } else {
                vector<int> result;
                if ((r - l + 1) % 2 == 0) {
                    result.push_back(l);
                    l++;
                }
                auto b = mp[pref[r] + pref[l - 1]];
                result.push_back(*lower_bound(b.begin(), b.end(), l));
                int k = result.size();
                cout << k << '\n';
                for (int i = 0; i < k; i++) {
                    cout << result[i];
                    if (i + 1 < k)
                        cout << ' ';
                }
                cout << '\n';
            }
        }
    }
    return 0;
}
