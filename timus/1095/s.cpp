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
        vector<int> p = { 1, 2, 3, 4 };
        vector<int> cnt(10, 0);
        for (int i = 0; i < n; i++) {
            cnt[s[i] - '0']++;
        }
        for (int i = 1; i <= 4; i++) cnt[i]--;
        int r = 0;
        for (int i = 1; i <= 9; i++) {
            for (int j = 0; j < cnt[i]; j++) {
                r = (r * 10 + i) % 7;
                cout << i;
            }
        }
        do {
            int t = r;
            for (int x : p) t = (t * 10 + x) % 7;
            if (t == 0) {
                for (int x : p) cout << x;
                for (int i = 0; i < cnt[0]; i++) cout << 0;
                cout << '\n';
                break;
            }
        } while (next_permutation(p.begin(), p.end()));
    }
    return 0;
}
