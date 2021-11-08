#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> g(n + 1);
        vector<int> deg(n + 1, 0);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
            deg[a]++;
            deg[b]++;
        }
        vector<int> leaves;
        for (int i = 1; i <= n; i++) {
            if (deg[i] <= 1) {
                leaves.push_back(i);
            }
        }
        int total = n;
        k = min(n, k);
        while (k--) {
            vector<int> leaves_next;
            for (int x : leaves) {
                for (int y : g[x]) {
                    deg[y]--;
                    if (deg[y] == 1) {
                        leaves_next.push_back(y);
                    }
                }
            }
            total -= leaves.size();
            leaves = leaves_next;
        }
        cout << total << '\n';
    }
    return 0;
}
