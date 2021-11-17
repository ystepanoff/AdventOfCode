/*
ID: dr.yste1
TASK: maze1
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "maze1"

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
    ifstream fin(PROBLEM ".in");
    ofstream fout(PROBLEM ".out");
    int m, n;
    fin >> m >> n;
    string s;
    getline(fin, s);
    vector<string> maze(2 * n + 1);
    for (int i = 0; i <= 2 * n; i++) {
        getline(fin, maze[i]);
    }
    vector<pair<int,int>> start;
    for (int i = 0; i <= 2 * n; i++) {
        if (maze[i][0] == ' ') start.emplace_back(i, 0);
        if (maze[i][2 * m] == ' ') start.emplace_back(i, 2 * m);
    }
    for (int j = 0; j <= 2 * m; j++) {
        if (maze[0][j] == ' ') start.emplace_back(0, j);
        if (maze[2 * n][j] == ' ') start.emplace_back(2 * n, j);
    }
    vector<vector<vector<int>>> dist;
    for (auto p : start) {
        int x = p.first, y = p.second;
        vector<pair<int,int>> q;
        vector<vector<bool>> visited(2 * n + 1, vector<bool>(2 * m + 1, false));
        vector<vector<int>> d(2 * n + 1, vector<int>(2 * m + 1, 0));
        q.push_back(make_pair(x, y));
        visited[x][y] = true;
        for (int i = 0; i < q.size(); i++) {
            x = q[i].first;
            y = q[i].second;
            for (int dir = 0; dir < 4; dir++) {
                int xx = x + dx[dir];
                int yy = y + dy[dir];
                if (xx >= 0 && yy >= 0 && xx <= 2 * n && yy <= 2 * m &&
                    !visited[xx][yy] && maze[xx][yy] == ' ') {
                    q.push_back(make_pair(xx, yy));
                    visited[xx][yy] = true;
                    d[xx][yy] = d[x][y] + 1;
                }
            }
        }
        dist.push_back(d);
    }
    int maxd = -1;
    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * m; j++) {
            dist[0][i][j] = min(dist[0][i][j], dist[1][i][j]);
            if (maxd == -1 || dist[0][i][j] > maxd) maxd = dist[0][i][j];
        }
    }
    fout << (maxd + 1) / 2 << '\n';
    fin.close();
    fout.close();
    return 0;
}
