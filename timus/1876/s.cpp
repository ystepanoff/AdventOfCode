#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    int best = 2 * b + 40;
    for (int x = 39; x >= 0; x--) {
        // x right first => T = 2 * x
        // all left => T = 2 * (a - 40) + 40
        // remaining 40 - x right => T = 40 - x
        best = max(best, 2 * x + 2 * (a - 40) + 40 + 40 - x);
    }
    cout << best << '\n';
    return 0;
}
