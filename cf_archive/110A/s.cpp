#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    while (cin >> n) {
        int c = 0;
        for (; n > 0; n /= 10)
            c += (n % 10 == 4 || n % 10 == 7);
        bool y = c > 0;
        for (; c > 0; c /= 10)
            y &= (c % 10 == 4 || c % 10 == 7);
        cout << (y ? "YES" : "NO") << '\n';
    }
    return 0;
}
