#include <bits/stdc++.h>
using namespace std;

int powmod(int a, int b, int m) {
    int r = 1;
    while (b) {
        if (b & 1)
            r = (r * a) % m, b--;
        a = (a * a) % m, b >>= 1;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, y;
    cin >> n >> m >> y;
    bool found = false;
    for (int x = 0; x < m; x++)
        if (powmod(x, n, m) == y) {
            cout << x << " ";
            found = true;
        }
    if (!found)
        cout << "-1";
    cout << '\n';
    return 0;
}
