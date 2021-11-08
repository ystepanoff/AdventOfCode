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
        int best = 1e9;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((s[i] == '0' && s[j] == '0') ||
                    (s[i] == '2' && s[j] == '5') ||
                    (s[i] == '5' && s[j] == '0') ||
                    (s[i] == '7' && s[j] == '5')) {
                    best = min(best, (n - 1 - j) + (j - i - 1));
                }
            }
        }
        if (find(s.begin(), s.end(), '0') != s.end()) {
            best = min(best, n - 1);
        }
        cout << best << '\n';
    }
    return 0;
}
