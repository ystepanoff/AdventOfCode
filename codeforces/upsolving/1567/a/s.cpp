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
        string t = s;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'U') t[i] = 'D';
            if (s[i] == 'D') t[i] = 'U';
        }
        cout << t << '\n';
    }
    return 0;
}
