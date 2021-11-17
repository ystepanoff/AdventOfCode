#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int p, m, c, k, r, v;
    cin >> p >> m >> c;
    cin >> k >> r >> v;
    cout << min(p / k, min(m / r, c / v)) << '\n';
    return 0;
}
