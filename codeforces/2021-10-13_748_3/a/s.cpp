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
        cout << max(0LL, max(b, c) - a + 1) << ' ';
        cout << max(0LL, max(a, c) - b + 1) << ' ';
        cout << max(0LL, max(a, b) - c + 1) << '\n';
    }
    return 0;
}
