#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    double x, y, z;
    cin >> x >> y >> z;
    x *= 60;
    y *= 60;
    cout << fixed << setprecision(7);
    double a = y - x - z, b = y - x;
    cout << 1 - a * a / b / b << '\n';
    return 0;
}
