#include <bits/stdc++.h>
using namespace std;

struct dsu {
    vector<int> p;

    dsu(int n) {
        p.resize(n + 1, 0);
    }

    void make_set(int i) {
        p[i] = i;
    }

    int find_set(int i) {
        return p[i] == i ? i : p[i] = find_set(p[i]);
    }

    void union_sets(int i, int j) {
        p[find_set(i)] = find_set(j);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    dsu uf1(n), uf2(n);
    for (int i = 1; i <= n; i++) {
        uf1.make_set(i);
        uf2.make_set(i);
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        uf1.union_sets(u, v);
    }
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        uf2.union_sets(u, v);
    }
    vector<pair<int,int>> e;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (uf1.find_set(i) != uf1.find_set(j) && uf2.find_set(i) != uf2.find_set(j)) {
                e.push_back(make_pair(i, j));
                uf1.union_sets(i, j);
                uf2.union_sets(i, j);
            }
    cout << e.size() << '\n';
    for (auto& p : e)
        cout << p.first << ' ' << p.second << '\n';
    return 0;
}
