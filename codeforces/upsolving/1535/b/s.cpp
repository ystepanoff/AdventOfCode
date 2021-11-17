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
        vector<int> a, b, c;
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            if (v & 1) {
                c.push_back(v);
            } else {
                b.push_back(v);
            }
        }
        for (int x : b) a.push_back(x);
        for (int x : c) a.push_back(x);
        int total = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (i != j && __gcd(a[i], 2 * a[j]) > 1) {
                    total++;
                }
            }
        }
        cout << total << '\n';
    }
    return 0;
}
