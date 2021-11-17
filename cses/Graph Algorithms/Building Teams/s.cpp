#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> col;
int n, m;

void dfs(int v, int c) {
    col[v] = c;
    for (int x : g[v])
        if (!col[x])
            dfs(x, (c % 2) + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    g.resize(n + 1);
    col.resize(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        if (!col[i])
            dfs(i, 1);
    for (int i = 1; i <= n; i++)
        for (int j : g[i])
            if (col[i] == col[j]) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
    for (int i = 1; i <= n; i++)
        cout << col[i] << ' ';
    cout << '\n';
    return 0;
}
