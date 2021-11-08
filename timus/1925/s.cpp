#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a += x;
        b += y;
    }
    a = a + k - 2 * (n + 1);
    if (a > b) {
        cout << a - b << '\n';
    } else {
        cout << "Big Bang!\n";
    }
    return 0;
}
