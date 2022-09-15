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
        vector<int> cnt(256, 0), right(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            right[i] = cnt[s[i]];
            cnt[s[i]]++;
        }
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (right[i]) {
                j++;
            } else {
                break;
            }
        }
        cout << s.substr(j) << '\n';
    }
    return 0;
}
