#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    if (n <= k) {
        cout << "2\n";
    } else {
        cout << (2 * n + k - 1) / k << '\n';
    }
    return 0;
}
