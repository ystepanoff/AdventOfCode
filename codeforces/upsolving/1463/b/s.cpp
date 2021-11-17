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
        vector<int> a(n), b1(n, 1), b2(n, 1);
        long long s = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
            if (i & 1) b1[i] = a[i]; else b2[i] = a[i];
        }
        long long t = 0;
        for (int i = 0; i < n; i++)
            t += abs(a[i] - b1[i]);
        if (2 * t <= s) {
            for (int x : b1)
                cout << x << ' ';
            cout << '\n';
        } else {
            for (int x : b2)
                cout << x << ' ';
            cout << '\n';
        }
    }
    return 0;
}
