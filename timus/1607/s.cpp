#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (c < a) {
        cout << a << '\n';
        return 0;
    }
    while (a < c) {
        a = min(a + b, c);
        c = max(a, c - d);
    }
    cout << c << '\n';
    return 0;
}
