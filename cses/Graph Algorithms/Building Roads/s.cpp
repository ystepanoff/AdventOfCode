#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<bool> u;
int n, m;

void dfs(int v) {
    u[v] = true;
    for (int x : g[v])
        if (!u[x])
            dfs(x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    g.resize(n + 1);
    u.resize(n + 1, false);
    while (m--) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<pair<int,int>> r;
    int last = -1;
    for (int i = 1; i <= n; i++)
        if (!u[i]) {
            dfs(i);
            if (last != -1)
                r.push_back(make_pair(last, i));
            last = i;
        }
    cout << r.size() << '\n';
    for (auto p : r)
        cout << p.first << ' ' << p.second << '\n';
    cout << '\n';
    return 0;
}
