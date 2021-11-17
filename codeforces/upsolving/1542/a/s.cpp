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
        vector<int> a(2, 0);
        for (int i = 0; i < 2 * n; i++) {
            int v;
            cin >> v;
            a[v & 1]++;
        }
        cout << (a[0] == a[1] ? "Yes" : "No") << '\n';
    }
    return 0;
}
