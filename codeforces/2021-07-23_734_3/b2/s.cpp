#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), cnt(n + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        vector<int> it(n + 1, 0);
        vector<int> b(n, 0);
        for (int i = 0; i < n; i++)
            if (cnt[a[i]] >= k) {
                if (it[a[i]] < k)
                    b[i] = ++it[a[i]];
            } else {
                b[i] = -1;
            }
        vector<pair<int,int>> c;
        for (int i = 0; i < n; i++)
            if (b[i] == -1)
                c.emplace_back(a[i], i);
        sort(c.begin(), c.end());
        int j = 0;
        for (int i = 0; i < (c.size() / k) * k; i++) {
            b[c[i].second] = j + 1; 
            j = (j + 1) % k;
        }
        for (int x : b)
            cout << max(x, 0) << ' ';
        cout << '\n';
    }
    return 0;
}
