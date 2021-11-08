#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        char c;
        cin >> n >> c;
        string s;
        cin >> s;
        vector<int> pos;
        for (int i = 0; i < n; i++) {
            if (s[i] != c) pos.push_back(i + 1);
        }
        if (pos.empty()) {
            cout << "0\n";
            continue;
        }
        if (s[n - 1] == c) {
            cout << "1\n" << n << '\n';
        } else {
            bool found = false;
            for (int i = n - 2; i >= 0; i--) {
                if (s[i] == c) {
                    bool can = true;
                    for (int x : pos) {
                        if (x % (i + 1) == 0) can = false;
                    }
                    if (can) {
                        cout << "1\n" << i + 1 << '\n';
                        found = true;
                        break;
                    }
                }
            }
            if (!found) {
                cout << "2\n" << n << ' ' << n - 1 << '\n';
            }
        }
    }
    return 0;
}
