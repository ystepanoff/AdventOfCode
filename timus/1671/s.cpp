#include <bits/stdc++.h>
using namespace std;

vector<int> p;

int find_set(int x) {
    return p[x] == x ? x : p[x] = find_set(p[x]);
}

void union_sets(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    p[x] = y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> edges(m);
    vector<bool> exists(m, true);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }
    int q;
    cin >> q;
    vector<int> a(q);
    for (int i = 0; i < q; i++) {
        cin >> a[i];
        a[i]--;
        exists[a[i]] = false;
    }
    p.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    for (int i = 0; i < m; i++) {
        if (exists[i]) {
            union_sets(edges[i].first, edges[i].second);
        }
    }
    vector<bool> seen(n + 1, false);
    int total = 0;
    for (int i = 1; i <= n; i++) {
        int s = find_set(i);
        if (!seen[s]) {
            seen[s] = true;
            total++;
        }
    }
    vector<int> result;
    for (int i = q - 1; i >= 0; i--) {
        result.push_back(total);
        if (find_set(edges[a[i]].first) != find_set(edges[a[i]].second)) {
            union_sets(edges[a[i]].first, edges[a[i]].second);
            total--;
        }
    }
    for (int i = q - 1; i >= 0; i--) {
        cout << result[i];
        if (i > 0) cout << ' ';
    }
    cout << '\n';
    return 0;
}
