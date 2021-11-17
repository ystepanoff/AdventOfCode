#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int k;
        cin >> k;
        // k / (100 - k)  = e / w
        // 3 / 97 = e / w
        // 25 / 75 = e / w => 1 / 3 = e / w
        int a = k, b = 100 - k;
        int g = __gcd(a, b);
        a /= g;
        b /= g;
        cout << a + b << '\n';
    }
    return 0;
}
