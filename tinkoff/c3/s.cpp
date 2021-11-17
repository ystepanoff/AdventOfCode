#include <bits/stdc++.h>
using namespace std;

bool leap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k, n;
    cin >> k >> n;
    int x = 0, y = 0;
    while (n--) {
        if (leap(k)) {
            x += 1;
            y += 2;
        } else {
            x += 2;
            y += 1;
        }
        k++;
    }
    cout << x << ' ' << y << '\n';
    return 0;
}
