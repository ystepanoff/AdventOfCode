#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int x = 0, y = 0;
    while (n--) {
        int v;
        cin >> v;
        if (v > k) x += v - k; else y += k - v;
    }
    cout << x << ' ' << y << '\n';
    return 0;
}
