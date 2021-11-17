#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        string s;
        cin >> n >> s;
        auto it = find(s.begin(), s.end(), '0');
        if (it == s.end()) {
            cout << "1 " << n / 2 << ' ' << n - (n / 2) + 1 << ' ' << n << '\n';
        } else {
            int p = (int)(it - s.begin());
            if (p < (n / 2)) {
                cout << (p + 1) << ' ' << n << ' ' << p + 2 << ' ' << n << '\n';
            } else {
                cout << 1 << ' ' << p + 1 << ' ' << 1 << ' ' << p << '\n';
            }
        }
    }
    return 0;
}
