#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin >> m;
    while (m--) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        int n = s.length();
        bool good = true;
        for (int i = 0; i < n; ) {
            if (i + 2 < n && !s.substr(i, 3).compare("tuo"))
                i += 3;
            else if (i + 5 < n && !s.substr(i, 6).compare("tuptuo"))
                i += 6;
            else if (i + 4 < n && !s.substr(i, 5).compare("notup"))
                i += 5;
            else if (i + 1 < n && !s.substr(i, 2).compare("ni"))
                i += 2;
            else if (i + 4 < n && !s.substr(i, 5).compare("tupni"))
                i += 5;
            else if (i + 2 < n && !s.substr(i, 3).compare("eno"))
                i += 3;
            else {
                good = false;
                break;
            }
        }
        cout << (good ? "YES" : "NO") << '\n';
    }
    return 0;
}
