#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    while (cin >> n >> k) {
        while (k--) {
            if (n % 10)
                n--;
            else
                n /= 10;
        }
        cout << n << '\n';
    }
    return 0;
}
