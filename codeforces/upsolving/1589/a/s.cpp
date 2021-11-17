#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        long long u, v;
        cin >> u >> v;
        cout << u * u << ' ' << -v * v << '\n';
    }
    return 0;
}
