#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        long long n, k;
        if (n % 2 == 0) {
            k %= n;
            cout << n - k << '\n';
        } else {
            k %= n * (n - 1) / 2;
            
        }
    }
    return 0;
}
