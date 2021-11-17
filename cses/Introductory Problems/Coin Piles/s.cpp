#include <bits/stdc++.h>
using namespace std;

bool solve(int a, int b) {
    if (a < b) swap(a, b);
    if ((a + b) % 3 != 0)
        return false;
    if (a > 2 * b)
        return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b;
        cin >> a >> b;
        cout << (solve(a, b) ? "YES" : "NO") << '\n';
    }
    return 0;
}
