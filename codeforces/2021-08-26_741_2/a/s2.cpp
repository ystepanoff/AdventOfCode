#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        long long l, r;
        cin >> l >> r;
        if ((r / 2) >= l) {
            cout << r % ((r >> 1) + 1) << '\n';
        } else {
            cout << r % l << '\n';
        }
    }
    return 0;
}
