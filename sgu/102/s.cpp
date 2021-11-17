#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int r = n;
    for (int c = 2; c * c <= n; c++)
        if (!(n % c)) {
            for (; !(n % c); n /= c);
            r -= r / c;
        }
    if (n > 1)
        r -= r / n;
    cout << r << '\n';
    return 0;
}
