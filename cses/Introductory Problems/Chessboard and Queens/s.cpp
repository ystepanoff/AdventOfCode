#include <bits/stdc++.h>
using namespace std;

vector<string> grid(8);
unordered_map<int,bool> ux, uy, ud1, ud2;
int total = 0;

void walk(int q, int x, int y) {
    if (q == 0) {
        total += 1;
        return;
    }
    if (y == 8) x += 1, y = 0;
    if (x == 8) return;

    if (!ux[x] && !uy[y] && !ud1[x + y] && !ud2[x - y] && grid[x][y] == '.') {
        ux[x] = uy[y] = ud1[x + y] = ud2[x - y] = true;
        walk(q - 1, x, y + 1);
        ux[x] = uy[y] = ud1[x + y] = ud2[x - y] = false;
    }
    walk(q, x, y + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < 8; i++)
        cin >> grid[i];
    walk(8, 0, 0);
    cout << total << '\n';
    return 0;
}
