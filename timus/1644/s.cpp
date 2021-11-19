#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int l = 2, r = 10;
    for (int i = 0; i < n; i++) {
        int x;
        string s;
        cin >> x >> s;
        if (!s.compare("hungry")) {
            l = max(l, x);
        } else {
            r = min(r, x);
        }
    }
    if (l < r) {
        cout << r << '\n';
    } else {
        cout << "Inconsistent\n";
    }
    return 0;
}
