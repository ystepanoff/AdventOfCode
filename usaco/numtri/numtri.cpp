/*
ID: dr.yste1
TASK: numtri
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "numtri"

int main() {
    ifstream fin(PROBLEM ".in");
    ofstream fout(PROBLEM ".out");
    int n;
    fin >> n;
    vector<vector<int>> t(n + 1, vector<int> (n + 1, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            fin >> t[i][j];
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j <= i; j++)
            t[i][j] += max(t[i + 1][j], t[i + 1][j + 1]);
    fout << t[0][0] << '\n';
    fin.close();
    fout.close();
    return 0;
}
