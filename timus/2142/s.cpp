#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    if (d > a) {
        c -= d - a;
        a = 0;
    } else {
        a -= d;
    }
    if (e > b) {
        c -= e - b;
        b = 0;
    } else {
        b -= e;
    }
    cout << (c >= 0 && a + b + c >= f ? "It is a kind of magic" : "There are no miracles in life") << '\n';
    return 0;
}
