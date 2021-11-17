#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    cout << n + m - 2 - __gcd(n - 1, m - 1) << '\n';
    return 0;
}
