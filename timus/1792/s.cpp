#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int A, B, C, D, a, b, c;
    cin >> A >> B >> C >> D >> a >> b >> c;
    int _a = (B + C + D) % 2;
    int _b = (A + C + D) % 2;
    int _c = (A + B + D) % 2;
    if (a != _a && b != _b && c != _c) {
        D = 1 - D;
    } else if (a != _a && b != _b) {
        C = 1 - C;
    } else if (a != _a && c != _c) {
        B = 1 - B;
    } else if (b != _b && c != _c) {
        A = 1 - A;
    } else if (a != _a) {
        a = 1 - a;
    } else if (b != _b) {
        b = 1 - b;
    } else if (c != _c) {
        c = 1 - c;
    }
    cout << A << ' ' << B << ' ' << C << ' ' << D << ' ' << a << ' ' << b << ' ' << c << '\n';
    return 0;
}
