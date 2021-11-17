#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b;
        cin >> a >> b;
        if ((a + b) & 1) {
            cout << "-1\n";
        } else {
            if (a == b) {
                cout << (a == 0 ? 0 : 1) << '\n';
            } else {
                cout << "2\n";
            }
        }
    }
    return 0;
}
