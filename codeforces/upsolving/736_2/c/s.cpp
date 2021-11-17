#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> w(n + 1), deg(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u < v)
            w[v]++;
        else
            w[u]++;
        deg[u]++;
        deg[v]++;
    }
    int total = 0;
    for (int i = 1; i <= n; i++)
        if (deg[i] == w[i])
            total++;
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        if (x < 3) {
            int u, v;
            cin >> u >> v;
            total -= (int)(deg[u] == w[u]);
            total -= (int)(deg[v] == w[v]);
            if (x == 1) {
                w[max(u, v)]++;
                deg[u]++;
                deg[v]++;
            } else {
                w[max(u, v)]--;
                deg[u]--;
                deg[v]--;
            }
            total += (int)(deg[u] == w[u]);
            total += (int)(deg[v] == w[v]);
        } else {
            cout << total << '\n';
        }
    }
    return 0;
}
