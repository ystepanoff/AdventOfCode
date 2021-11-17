#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n, k;
    while (cin >> n >> k) {
        if (k <= (n + 1) / 2)
            cout << 2 * k - 1 << "\n";
        else
            cout << 2 * (k - (n + 1) / 2) << "\n";
    }
    return 0;
}
