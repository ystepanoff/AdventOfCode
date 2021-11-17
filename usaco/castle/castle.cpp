/*
ID: dr.yste1
TASK: castle
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "castle"

vector<vector<int>> a, id;
vector<int> sizes(1);

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };
char dw[4] = { 'W', 'N', 'E', 'S' };

int dfs(int curr, int x, int y) {
    id[x][y] = curr;
    int s = 0;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (!(a[x][y] & (1 << i)) && !id[xx][yy]) {
            s += dfs(curr, xx, yy);
        }
    }
    return 1 + s;
}

int main() {
    ifstream fin(PROBLEM ".in");
    ofstream fout(PROBLEM ".out");
    int m, n;
    fin >> n >> m;
    a.assign(m, vector<int>(n));
    id.assign(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fin >> a[i][j];
        }
    }
    int total = 0, largest = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!id[i][j]) {
                total++;
                int s = dfs(total, i, j);
                sizes.push_back(s);
                largest = max(largest, s);
            }
        }
    }
    fout << total << '\n' << largest << '\n';
    int best = 0;
    int bestx, besty, bestdir;
    for (int y = 0; y < n; y++) {
        for (int x = m - 1; x >= 0; x--) {
            for (int dir = 0; dir < 4; dir++) {
                if (a[x][y] & (1 << dir)) {
                    int xx = x + dx[dir];
                    int yy = y + dy[dir];
                    if (xx >= 0 && yy >= 0 && xx < m && yy < n && id[x][y] != id[xx][yy]) {
                        int s = sizes[id[x][y]] + sizes[id[xx][yy]];
                        if (s > best) {
                            best = s;
                            bestx = x + 1;
                            besty = y + 1;
                            bestdir = dir;
                        }
                    }
                }
            }
        }
    }
    fout << best << '\n' << bestx << ' ' << besty << ' ' << dw[bestdir] << '\n';
    fin.close();
    fout.close();
    return 0;
}

