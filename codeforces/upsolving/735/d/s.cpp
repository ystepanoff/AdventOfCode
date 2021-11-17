#include <bits/stdc++.h>
using namespace std;

bool is_prime(int x) {
    for (int c = 2; c * c <= x; c++) {
        if (!(x % c)) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (n & 1) {
        cout << (is_prime(n) ? 1 : is_prime(n - 2) ? 2 : 3) << '\n';
    } else {
        cout << (n == 2 ? 1 : 2) << '\n';
    }
    return 0;
}
