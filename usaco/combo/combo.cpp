/*
ID: dr.yste1
TASK: combo
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "combo"

int main() {
    ifstream fin(PROBLEM ".in");
    ofstream fout(PROBLEM ".out");
    int n, a, b, c, d, e, f;
    fin >> n;
    fin >> a >> b >> c; a--; b--; c--;
    fin >> d >> e >> f; d--; e--; f--;
    int good[110][110][110] = { 0 };
    for (int i = -2; i <= 2; i++)
        for (int j = -2; j <= 2; j++)
            for (int k = -2; k <= 2; k++) {
                good[(a + i + n) % n][(b + j + n) % n][(c + k + n) % n] = 1;
                good[(d + i + n) % n][(e + j + n) % n][(f + k + n) % n] = 1;
            }
    int total = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                total += good[i][j][k];
    fout << total << '\n';
    return 0;
}
