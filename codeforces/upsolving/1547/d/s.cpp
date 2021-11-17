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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b = { 0 };
        vector<int> c = { a[0] };
        for (int i = 1; i < n; i++) {
            if ((c[i - 1] & a[i]) != c[i - 1]) {
                int x = 0;
                for (int j = 0; j < 30; j++) {
                    if (c[i - 1] & (1 << j) && !(a[i] & (1 << j))) {
                        x |= 1 << j;
                    }
                }
                b.push_back(x);
                c.push_back(a[i] ^ x);
            } else {
                b.push_back(0);
                c.push_back(a[i]);
            }
        }
        for (int i = 0; i < n; i++) {
            cout << b[i];
            if (i < n - 1) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
