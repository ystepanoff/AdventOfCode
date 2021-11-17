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
        int a = 0, b = 0, c = 0;
        for (char ch : s) {
            if (ch == 'A') a++;
            if (ch == 'B') b++;
            if (ch == 'C') c++;
        }
        int n = s.length();
        if (!(n & 1) && b == (n >> 1)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
