#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << "0\n";
            continue;
        }
        int s = n;
        for (int i = n - 1; i >= 1; i--) {
            s &= i;
            if (!s) {
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}
