#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> u, d;

void dfs(int v) {
    u[v] = 1;
    int t = 0;
    for (int x : g[v]) {
        dfs(x);
        t += d[x];
    }
    d[v] = 1 + t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    g.resize(n + 1);
    u.resize(n + 1, 0);
    d.resize(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        int b;
        cin >> b;
        g[b].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        cout << d[i] - 1 << ' ';
    cout << '\n';
    return 0;
}
