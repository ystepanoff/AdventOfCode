#include <bits/stdc++.h>
using namespace std;
 
vector<string> paths;
string curr = string(48, ' ');
bool grid[9][9];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
string dir = "DLUR";
 
void gen(int x, int y, int n) {
    if (n == 48 && x == 7 && y == 1) {
        paths.push_back(curr);
        return;
    }
    if (x == 7 && y == 1) return;
    if (n > 0) {
        if (curr[n - 1] == 'D' && grid[x + 1][y] && !grid[x][y - 1] && !grid[x][y + 1]) return;
        if (curr[n - 1] == 'U' && grid[x - 1][y] && !grid[x][y - 1] && !grid[x][y + 1]) return;
        if (curr[n - 1] == 'R' && grid[x][y + 1] && !grid[x - 1][y] && !grid[x + 1][y]) return;
        if (curr[n - 1] == 'L' && grid[x][y - 1] && !grid[x - 1][y] && !grid[x + 1][y]) return;
    }
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (!grid[xx][yy]) {
            curr[n] = dir[i];
            grid[xx][yy] = true;
            gen(xx, yy, n + 1);
            grid[xx][yy] = false;
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < 9; i++) {
        grid[i][0] = grid[0][i] = true;
        grid[i][8] = grid[8][i] = true;
    }
    grid[1][1] = true;
    gen(1, 1, 0);
    string s;
    cin >> s;
    int total = 0;
    for (string p : paths) {
        bool match = true;
        for (int i = 0; i < 48; i++)
            match &= s[i] == '?' || (s[i] != '?' && s[i] == p[i]);
        if (match)
            total++;
    }
    cout << total << '\n';
    return 0;
}
