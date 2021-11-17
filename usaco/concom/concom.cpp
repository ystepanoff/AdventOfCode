/*
ID: dr.yste1
TASK: concom
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "concom"

const int n = 100;
int u[n + 1], total[n + 1], a[n + 1][n + 1];

void dfs(int v) {
    u[v] = 1;
    for (int i = 1; i <= n; i++) 
        total[i] += a[v][i];
    for (int i = 1; i <= n; i++)
        if (!u[i] && total[i] > 50)
            dfs(i);
}

int main() {
    ifstream fin(PROBLEM ".in");
    ofstream fout(PROBLEM ".out");
    int m;
    fin >> m;
    while (m--) {
        int x, y, c;
        fin >> x >> y >> c;
        a[x][y] += c;
    }
    for (int i = 1; i <= n; i++) {
        memset(u, 0, sizeof(u));
        memset(total, 0, sizeof(total));
        dfs(i);
        for (int j = 1; j <= n; j++)
            if (i != j && total[j] > 50) {
                fout << i << ' ' << j << '\n';
            }
    }
    fin.close();
    fout.close();
    return 0;
}
