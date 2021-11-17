#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (!(n & 1)) return false;
    for (int c = 3; c * c <= n; c++)
        if (!(n % c))
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        bool yes = false;
        for (int c = 2; c * c <= n; c++)
            if (!(n % c) && is_prime(c) && is_prime(n / c)) {
                yes = true;
                break;
            }
        cout << (yes ? "Yes" : "No") << '\n';
    }
    return 0;
}
