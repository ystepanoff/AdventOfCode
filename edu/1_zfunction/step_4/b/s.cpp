#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s, t;
        cin >> s >> t;
        int n = s.length();
        string p = t + '$' + s + s;
        int m = 3 * n + 1;
        vector<int> z(m, 0);
        for (int i = 1, l = 0, r = 0; i < m; i++) {
            if (r >= i)
                z[i] = min(z[i - l], r - i + 1);
            while (i + z[i] < m && p[i + z[i]] == p[z[i]])
                z[i]++;
            if (i + z[i] - 1 > r)
                l = i, r = i + z[i] - 1;
        }
        int k = -1;
        for (int i = n; i < m; i++)
            if (z[i] == n) {
                k = i - n - 1;
                break;
            }
        cout << k << '\n';
    }
    return 0;
}
