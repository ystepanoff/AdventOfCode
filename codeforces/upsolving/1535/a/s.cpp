#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        vector<int> a(4);
        for (int i = 0; i < 4; i++) {
            cin >> a[i];
        }
        int x = max(a[0], a[1]);
        int y = max(a[2], a[3]);
        sort(a.begin(), a.end());
        if (x + y == a[2] + a[3]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
