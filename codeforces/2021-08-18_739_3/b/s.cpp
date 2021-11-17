#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b)
            swap(a, b);
        int n = b - a;
        if (!(c >= 1 && c <= (n << 1)) || !(a >= 1 && a <= n) || !(b >= n + 1 && b <= (n << 1))) {
            cout << "-1\n";
        } else {
            cout << (c > n ? c - n : c + n) << '\n';
        }
    }
    return 0;
}
