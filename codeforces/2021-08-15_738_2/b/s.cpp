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
        string s;
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < n; i++) 
            if (s[i] == '?')
                cnt++;
        if (cnt == n) {
            for (int i = 0; i < n; i++)
                cout << (i & 1 ? 'R' : 'B');
            cout << '\n';
            continue;
        }
        while (find(s.begin(), s.end(), '?') != s.end()) {
            for (int i = 1; i < n; i++) {
                if (s[i] == '?' && s[i - 1] == 'R')
                    s[i] = 'B';
                if (s[i] == '?' && s[i - 1] == 'B')
                    s[i] = 'R';
            }
            for (int i = n - 2; i >= 0; i--) {
                if (s[i] == '?' && s[i + 1] == 'R')
                    s[i] = 'B';
                if (s[i] == '?' && s[i + 1] == 'B')
                    s[i] = 'R';
            }
        }
        cout << s << '\n';
    }
    return 0;
}
