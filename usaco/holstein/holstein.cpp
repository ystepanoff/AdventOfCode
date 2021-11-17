/*
ID: dr.yste1
TASK: holstein
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "holstein"

int main() {
    ifstream fin(PROBLEM ".in");
    ofstream fout(PROBLEM ".out");
    int n;
    fin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }
    int m;
    fin >> m;
    vector<vector<int>> b(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fin >> b[i][j];
        }
    }
    int best = -1, bestmask = -1;
    for (int mask = 0; mask < (1 << m); mask++) {
        bool good = true;
        int count = __builtin_popcount(mask);
        for (int i = 0; i < n; i++) {
            int s = 0;
            for (int j = 0; j < m; j++) {
                if (mask & (1 << j)) {
                    s += b[j][i];
                }
            }
            good &= s >= a[i];
        }
        if (good) {
            if (best == -1 || count < best) {
                best = count;
                bestmask = mask;
            }
        }
    }
    fout << best << ' ';
    vector<int> r;
    for (int i = 0; i < m; i++) {
        if (bestmask & (1 << i)) r.push_back(i + 1);
    }
    for (int i = 0; i < r.size(); i++) {
        fout << r[i];
        if (i + 1 < r.size()) fout << ' ';
    }
    fout << '\n';
    fin.close();
    fout.close();
    return 0;
}
