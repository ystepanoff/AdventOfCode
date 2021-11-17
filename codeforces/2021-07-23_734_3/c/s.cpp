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
        vector<string> w(n);
        vector<vector<int>> cnt(n, vector<int>(256, 0));
        for (int i = 0; i < n; i++) {
            cin >> w[i];
            for (char c : w[i])
                cnt[i][c]++;
        }
        int best = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            vector<int> a(n);
            iota(a.begin(), a.end(), 0);
            sort(a.begin(), a.end(), [c, &w, &cnt](int i, int j) {
                int x = cnt[i][c], y = cnt[j][c];
                return 2 * x - (int)w[i].length() < 2 * y - (int)w[j].length();
            });
            int total = 0, x = 0, y = 0;
            for (int i = n - 1; i >= 0; i--) {
                x += cnt[a[i]][c];
                y += w[a[i]].length() - cnt[a[i]][c];
                if (x > y) {
                    total = n - i;
                }
            }
            best = max(best, total);
        }
        cout << best << '\n';
    }
    return 0;
}
