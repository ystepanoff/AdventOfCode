#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while (cin >> s) {
        int n = s.size();
        bool all = true;
        bool butfirst = true;
        bool first = s[0] >= 'A' && s[0] <= 'Z';
        for (int i = 0; i < n; i++) {
            all &= s[i] >= 'A' && s[i] <= 'Z';
            if (i > 0)
                butfirst &= s[i] >= 'A' && s[i] <= 'Z';
        }
        if (all || (!first && butfirst)) {
            for (int i = 0; i < n; i++)
                if (s[i] >= 'a' && s[i] <= 'z')
                    cout << (char)toupper(s[i]);
                else
                    cout << (char)tolower(s[i]);
            cout << '\n';
        } else {
            cout << s << '\n';
        }
    }
    return 0;
}
