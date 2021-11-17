#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> t;
vector<int> parent, ore, c;
vector<bool> visited;

void dfs1(int v) {
    visited[v] = true;
    ore[v] += c[v];
    for (int x : t[v]) {
        if (!visited[x]) {
            ore[x] += ore[v];
            parent[x] = v;
            dfs1(x);
        }
    }
}

vector<vector<bool>> banned;
vector<int> o;
vector<bool> u;

void dfs2(int v) {
    u[v] = true;
    o[v] += c[v];
    for (int x : t[v]) {
        if (!u[x] && !banned[v][x]) {
            o[x] += o[v];
            dfs2(x);
        }
    }
}

int solve(int v) {
    int n = t.size();
    banned.assign(n, vector<bool>(n, false));
    o.assign(n, 0);
    u.assign(n, false);
    for (int i = v; parent[i] != -1; i = parent[i]) {
        banned[parent[i]][i] = true;
        banned[i][parent[i]] = true;
    }
    dfs2(0);
    int best = 0;
    for (int i = 0; i < n; i++) {
        if (u[i] && i != v) best = max(best, o[i]);
    }
    return best;
}

int solve() {
    int n;
    cin >> n;
    t.assign(n, vector<int>());
    parent.assign(n, -1);
    visited.assign(n, false);
    ore.assign(n, 0);
    c.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    dfs1(0);
    c[0] = 0;
    int best = 0;
    for (int v = 0; v < n; v++) {
        best = max(best, ore[v] + solve(v));
    }
    return best;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    for (int _t = 1; _t <= tt; _t++) {
        cout << "Case #" << _t << ": " << solve() << '\n';
    }
    return 0;
}
