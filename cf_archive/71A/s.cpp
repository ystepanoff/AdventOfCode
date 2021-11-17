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
        if (n > 10) {
            string t = s[0] + to_string(n-2) + s[n-1];
            cout << t << '\n';
        } else {
            cout << s << '\n';
        }
    }
    return 0;
}
