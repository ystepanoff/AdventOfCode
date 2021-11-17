#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        int n = s.length();
        vector<int> z(n, 0);
        for (int i = 1, l = 0, r = 0; i < n; i++) {
            if (r >= i)
                z[i] = min(z[i - l], r - i + 1);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                z[i]++;
            if (i + z[i] - 1 > r)
                l = i, r = i + z[i] - 1;
        }
        sort(z.begin(), z.end());
        for (int i = 0; i < n; i++) {
            cout << (int)(z.end() - upper_bound(z.begin(), z.end(), i)) + 1;
            if (i < n - 1)
                cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
