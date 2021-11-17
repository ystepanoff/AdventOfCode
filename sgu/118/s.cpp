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
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        long long r = 0, c = 1;
        for (int i = 0; i < n; i++) {
            c = (c * a[i]) % 9;
            r = (r + c) % 9;
        }
        cout << (r ? r : 9) << '\n';
    }
    return 0;
}
