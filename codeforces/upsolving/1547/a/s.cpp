#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int xa, ya;
        int xb, yb;
        int xf, yf;
        cin >> xa >> ya;
        cin >> xb >> yb;
        cin >> xf >> yf;
        if (xa == xb) {
            cout << (xa == xf && min(ya, yb) <= yf && yf <= max(ya, yb) ? 2 : 0) + abs(ya - yb) << '\n';
        } else if (ya == yb) {
            cout << (ya == yf && min(xa, xb) <= xf && xf <= max(xa, xb) ? 2 : 0) + abs(xa - xb) << '\n';
        } else {
            cout << abs(xa - xb) + abs(ya - yb) << '\n';
        }
    }
    return 0;
}
