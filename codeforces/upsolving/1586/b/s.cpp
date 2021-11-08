#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<bool> u(n + 1);
        while (m--) {
            int a, b, c;
            cin >> a >> b >> c;
            u[b] = true;
        }
        int s = 1;
        while (u[s]) s++;
        for (int i = 1; i <= n; i++) {
            if (i != s) {
                cout << i << ' ' << s << '\n';
            }
        }
    }
    return 0;
}
