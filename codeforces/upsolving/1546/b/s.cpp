#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> cnt(m, vector<int>(256, 0));
        vector<string> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            for (int j = 0; j < m; j++)
                cnt[j][a[i][j]]++;
        }
        for (int i = 0; i < n - 1; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
                cnt[j][s[j]]--;
        }
        for (int i = 0; i < n; i++) {
            vector<vector<int>> cnt1(m, vector<int>(256, 0));
            for (int j = 0; j < m; j++)
                cnt1[j][a[i][j]]++;
            bool ok = true;
            for (int j = 0; j < m; j++)
                for (char c = 'a'; c <= 'z'; c++)
                    ok &= cnt[j][c] == cnt1[j][c];
            if (ok) {
                cout << a[i] << '\n';
                cout.flush();
                break;
            }
        }
    }
    return 0;
}
