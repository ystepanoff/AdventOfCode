#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++) {
        int d;
        cin >> d;
        while (d--) {
            int v;
            cin >> v;
            g[i].push_back(v);
            g[v].push_back(i);
        }
    }
    vector<int> d(n + 1, -1), q, r;
    q.push_back(x);
    d[x] = 0;
    for (int i = 0; i < q.size(); i++)
        for (int v : g[q[i]])
            if (d[v] == -1) {
                q.push_back(v);
                d[v] = d[q[i]] + 1;
            }
    for (int i = 1; i <= n; i++)
        if (d[i] == 2)
            r.push_back(i);
    cout << r.size() << '\n';
    for (int x : r)
        cout << x << ' ';
    cout << '\n';
    return 0;
}
