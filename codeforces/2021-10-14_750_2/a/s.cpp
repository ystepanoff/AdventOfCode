#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        long long a, b, c;
        cin >> a >> b >> c;
        cout << (a + 2 * b + 3 * c) % 2 << '\n';
    }
    return 0;
}
