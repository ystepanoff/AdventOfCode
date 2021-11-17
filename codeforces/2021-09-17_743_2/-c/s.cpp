#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> g;
vector<int> col, dp;
bool cycle;

void dfs(int v) {
    col[v] = 1;
    int mx = 0;
    for (auto p : g[v]) {
        if (col[p.first] == 1) {
            cycle = true;
            return;
        }
        if (!col[p.first]) {
            dfs(p.first);
            dp[v] = max(dp[v], dp[p.first] + p.second);
        }
    }
    col[v] = 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        g.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            int k;
            cin >> k;
            while (k--) {
                int j;
                cin >> j;
                g[i].emplace_back(j, (int)(i < j));
            }
        }
        col.resize(n + 1, 0);
        dp.resize(n + 1, 1);
        cycle = false;
        for (int i = 1; i <= n; i++) {
            if (!col[i]) dfs(i);
        }
        for (int i = 1; i <= n; i++) 
            cout << dp[i] << ' ';
        cout << '\n';
        g.clear();
    }
    return 0;
}
