#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
    for (int c = 2; c * c <= n; c++) {
        if (!(n % c))
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int s = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
        }
        if (is_prime(s)) {
            for (int i = 0; i < n; i++) {
                if (a[i] & 1) {
                    cout << n - 1 << '\n';
                    for (int j = 0; j < n; j++) {
                        if (i != j) cout << j + 1 << ' ';
                    }
                    cout << '\n';
                    break;
                }
            }
        } else {
            cout << n << '\n';
            for (int i = 0; i < n; i++) {
                cout << i + 1 << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
