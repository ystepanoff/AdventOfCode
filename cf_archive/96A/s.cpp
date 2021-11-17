#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while (cin >> s) {
        int n = s.length();
        bool g = true;
        int c = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == s[i - 1])
                c++;
            else
                c = 0;
            if (c == 6)
                g = false;
        }
        cout << (g ? "NO" : "YES") << '\n';
    }
    return 0;
}
