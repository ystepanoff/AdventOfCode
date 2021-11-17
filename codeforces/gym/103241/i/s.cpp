#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> t;

void update(int x, int y, int v) {
    for (int i = x; i < t.size(); i += i & -i)
        for (int j = y; j < t[i].size(); j += j & -j)
            t[i][j] = min(t[i][j], v);
}

int min_t(int x, int y) {
    int r = 1e9 + 7;
    for (int i = x; i > 0; i -= i & -i)
        for (int j = y; j > 0; j -= j & -j)
            r = min(r, t[i][j]);
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    t.resize(n + 1, vector<int> (m + 1, 1e9 + 7));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            int v;
            cin >> v;
            update(i, j, v);
        }
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << min_t(x, y) << '\n';
    }
    return 0;
}
