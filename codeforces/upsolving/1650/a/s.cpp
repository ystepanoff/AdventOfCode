#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s, t;
        cin >> s >> t;
        bool yes = false;
        for (int i = 0; i < s.length(); i += 2)
            if (s[i] == t[0]) yes = true;
        cout << (yes ? "yes" : "no") << '\n';
    }
    return 0;
}
