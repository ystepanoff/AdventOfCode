/*
ID: dr.yste1
TASK: wormhole
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "wormhole"

const int MAXN = 12;
int n, x[MAXN + 1], y[MAXN + 1];
int match[MAXN + 1], nxt[MAXN + 1];

int count() {
    int i;
    for (i = 1; i <= n; i++)
        if (match[i] == 0)
            break;
    if (i > n) {
        for (int j = 1; j <= n; j++) {
            int p = j;
            for (int k = 0; k < n; k++)
                p = nxt[match[p]];
            if (p)
                return 1;
        }
        return 0;
    }
    int r = 0;
    for (int j = i + 1; j <= n; j++)
        if (match[j] == 0) {
            match[i] = j;
            match[j] = i;
            r += count();
            match[i] = match[j] = 0;
        }
    return r;
}

int main() {
    ifstream fin(PROBLEM ".in");
    ofstream fout(PROBLEM ".out");

    fin >> n;
    for (int i = 1; i <= n; i++)
        fin >> x[i] >> y[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (y[j] == y[i] && x[j] > x[i] && (nxt[i] == 0 || x[j] < x[nxt[i]]))
                nxt[i] = j;

    fout << count() << '\n';

    fin.close();
    fout.close();
    return 0;
}
