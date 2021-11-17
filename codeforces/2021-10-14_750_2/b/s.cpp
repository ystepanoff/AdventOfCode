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
        int cz = 0, co = 0;
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            if (v == 0) cz++;
            if (v == 1) co++;
        }
        long long r = co;
        for (int i = 0; i < cz; i++) {
            r *= 2;
        }
        cout << r << '\n';
    }
    return 0;
}
