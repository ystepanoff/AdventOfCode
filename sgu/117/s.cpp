#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int total = 0;
    while (n--) {
        int a, b = m, r = 1;
        cin >> a;
        while (b > 0) {
            if (b & 1)
                r = (r * a) % k, b--;
            a = (a * a) % k, b >>= 1;
        }
        if (!r) total++;
    }
    cout << total << '\n';
    return 0;
}
