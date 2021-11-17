#include <bits/stdc++.h>
using namespace std;

const double pi = 3.1415926535;
const double g = 10.0;
const double eps = 1e-8;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    double v, a, k;
    cin >> v >> a >> k;
    double s = 0.0;
    while (v > eps) {
        s += v * v * sin(a * pi / 90) / g;
        v /= sqrt(k);
    }
    cout << fixed << setprecision(2);
    cout << s << '\n';
    return 0;
}
