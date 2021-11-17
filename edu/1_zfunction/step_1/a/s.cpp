#include <bits/stdc++.h>
using namespace std;

bool is_pal(string &s) {
    for (int l = 0, r = s.length() - 1; l < r; l++, r--)
        if (s[l] != s[r])
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        string t = "";
        int best = 0;
        for (int i = 0; i < s.length(); i++) {
            t += s[i];
            if (is_pal(t))
                best = i + 1;
        }
        cout << best << '\n';
    }
    return 0;
}
