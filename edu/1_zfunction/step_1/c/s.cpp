#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s, p;
        cin >> s >> p;
        int n = s.length(), m = p.length();
        vector<int> r;
        for (int i = 0; i < n - m + 1; i++) {
            bool match = true;
            for (int j = 0; j < m; j++)
                if (s[i + j] != p[j] && p[j] != '?') {
                    match = false;
                    break;
                }
            if (match) {
                r.push_back(i);
            }
        }
        cout << r.size() << '\n';
        for (int i = 0; i < r.size(); i++) {
            cout << r[i];
            if (i < r.size() - 1)
                cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
