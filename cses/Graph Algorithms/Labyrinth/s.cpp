#include <bits/stdc++.h>
using namespace std;

vector<string> g;
vector<vector<bool>> u;
vector<vector<int>> d, p;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
string dir = "RDLU";
int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    g.resize(n);
    u.resize(n, vector<bool> (m, false));
    d.resize(n, vector<int> (m, 0));
    p.resize(n, vector<int> (m, -1));
    int x1, y1, x2, y2;
    for (int i = 0; i < n; i++) {
        cin >> g[i];
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'A')
                x1 = i, y1 = j;
            if (g[i][j] == 'B')
                x2 = i, y2 = j;
        }
    }
    vector<pair<int,int>> q;
    q.push_back(make_pair(x1, y1));
    u[x1][y1] = true;
    for (int k = 0; k < q.size(); k++) 
        for (int i = 0; i < 4; i++) {
            int x = q[k].first + dx[i], y = q[k].second + dy[i];
            if (x >= 0 && y >= 0 && x < n && y < m)
                if (!u[x][y] && g[x][y] != '#') {
                    q.push_back(make_pair(x, y));
                    u[x][y] = true;
                    d[x][y] = d[q[k].first][q[k].second] + 1;
                    p[x][y] = i;
                }
        }
    if (u[x2][y2]) {
        cout << "YES\n";
        int dist = d[x2][y2];
        cout << dist << '\n';
        string route = "";
        for (int i = 0; i < dist; i++) {
            int k = p[x2][y2];
            route += dir[k];
            x2 -= dx[k], y2 -= dy[k];
        }
        cout << string(route.rbegin(), route.rend()) << '\n';
    } else {
        cout << "NO\n";
    }
    return 0;
}
