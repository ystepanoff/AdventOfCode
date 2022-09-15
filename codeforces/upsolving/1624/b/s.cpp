#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        long long a, b, c;
        cin >> a >> b >> c;
        bool yes = false;
        {
            int d = c - b;
            if ((b - d) % a == 0) yes = true;
            cout << "a" << ' ' << d << '\n';
        }
        {
            int d2 = c - a;
            if (d2 % 2 == 0) {
                int d = d2 / 2;
                if ((a + d) % b == 0 && (c - d) % b == 0) yes = true;
                cout << "b" << ' ' << d << '\n';
            }
        }
        {
            int d = b - a;
            if ((b + d) % c == 0) yes = true;
            cout << "c" << ' ' << d << '\n';
        }
        cout << (yes ? "YES" : "NO") << '\n';
    }
    return 0;
}
