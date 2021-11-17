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
        int total = 0;
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++) {
                string t = s.substr(i, j - i + 1);
                string a = s.substr(0, j - i + 1);
                string b = s.substr(n - (j - i + 1), j - i + 1);
                int c = 0;
                c += (int)(!a.compare(t));
                c += (int)(!b.compare(t));
                total += (int)(c == 1);
            }
        cout << total << '\n';
    }
    return 0;
}
