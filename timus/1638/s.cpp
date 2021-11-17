#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (c == d) {
        cout << a << '\n';
    } else if (c < d) {
        cout << (d - c) * 2 * b + (d - c - 1) * a << '\n';
    } else {
        cout << (c - d + 1) * a + (c - d) * 2 * b << '\n';
    }
    return 0;
}
