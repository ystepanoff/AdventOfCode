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
        auto it = find(s.begin(), s.end(), 'a');
        if (it == s.end()) {
            cout << "NO\n";
            continue;
        }
        int l = it - s.begin();
        int r = l;
        bool yes = true;
        char c = 'a';
        for (int i = 1; i < n; i++) {
            if (l > 0 && s[l - 1] == c + 1) {
                l--;
                c++;
            } else if (r < n - 1 && s[r + 1] == c + 1) {
                r++;
                c++;
            } else {
                yes = false;
                break;
            }
        }
        cout << (yes ? "YES" : "NO") << '\n';
    }
    return 0;
}
