#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s, p;
        cin >> s >> p;
        long long n = s.length(), m = p.length();
        long long total = 0;
        int l = 0;
        int matches = 0;
        for (int i = 0; i < n - m + 1; i++) {
            bool match = true;
            for (int j = 0; j < m; j++)
                if (s[i + j] != p[j]) {
                    match = false;
                    break;
                }
            if (match) {
                long long x = i + m - 1 - l;
                total += x * (x + 1) / 2;
                l = i + 1;
                matches++;
            }
        }
        total += ((long long)(n - l) * (long long)(n - l + 1)) / 2;
        if (m >= 2)
            total -= (long long)matches * (m - 2) * (m - 1) / 2;
        cout << total << '\n';
    }
    return 0;
}
