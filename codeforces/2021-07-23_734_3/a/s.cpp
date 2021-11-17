#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int x = n / 3, y = n % 3;
        int a = x, b = x;
        if (y > 0) {
            if (y == 1) a++; else b++;
        }
        cout << a << ' ' << b << '\n';
    }
    return 0;
}
