#include <bits/stdc++.h>
using namespace std;

vector<string> g;
vector<vector<bool>> u;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int n, m;

void dfs(int x, int y) {
    u[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx >= 0 && yy >= 0 && xx < n && yy < m)
            if (!u[xx][yy] && g[xx][yy] == '.')
                dfs(xx, yy);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    g.resize(n);
    u.resize(n, vector<bool> (m, false));
    for (int i = 0; i < n; i++)
        cin >> g[i];
    int total = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == '.' && !u[i][j]) {
                dfs(i, j);
                total++;
            }
    cout << total << '\n';
    return 0;
}
