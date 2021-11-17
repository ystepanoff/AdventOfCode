#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<bool> u(n + 1);
    vector<int> p(n + 1, -1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> q;
    q.push_back(1);
    u[1] = true;
    for (int i = 0; i < q.size(); i++)
        for (int v : g[q[i]])
            if (!u[v]) {
                q.push_back(v);
                u[v] = true;
                p[v] = q[i];
            }
    if (u[n]) {
        vector<int> r;
        for (int i = n; p[i] != -1; i = p[i])
            r.push_back(i);
        r.push_back(1);
        cout << r.size() << '\n';
        for (int i = r.size() - 1; i >= 0; i--)
            cout << r[i] << ' ';
        cout << '\n';
    } else {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}
