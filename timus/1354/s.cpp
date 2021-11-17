#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    string best = s + string(s.rbegin(), s.rend());
    for (int k = 0; k < 2; k++) {
        for (int i = 0; i + k < n; i++)
            for (int l = i, r = i + k; l >= 0 && r < n; l--, r++) {
                if (s[l] != s[r]) break;
                if (r == n - 1 && l > 0) {
                    string p = s.substr(0, l);
                    string t = s + string(p.rbegin(), p.rend());
                    if (t.length() < best.length()) {
                        best = t;
                    }
                }
            }
    }
    cout << best << '\n';
    return 0;
}
