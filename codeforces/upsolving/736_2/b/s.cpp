#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        string s, t;
        cin >> n >> s >> t;
        int total = 0;
        for (int i = 0; i < n; i++)
            if (t[i] == '1') {
                if (i > 0 && s[i - 1] == '1') {
                    total++;
                    s[i - 1] = '0';
                } else if (s[i] == '0') {
                    total++;
                } else if (s[i + 1] == '1') {
                    total++;
                    s[i + 1] = '0';
                }
            }
        cout << total << '\n';
    }
    return 0;
}
