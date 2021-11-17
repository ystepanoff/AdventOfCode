#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> g(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if (k == 2) {
            cout << n * (n - 1) / 2 % mod << '\n';
            return 0;
        }
        long long result = 0;
        for (int Q = 1; Q <= n; Q++) {
            int m = g[Q].size();
            vector<int> cnt(m + 1, 0);

        }
    }
    return 0;
}
