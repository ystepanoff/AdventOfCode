/*
ID: dr.yste1
TASK: barn1
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "barn1"

int main() {
    ifstream fin(PROBLEM ".in");
    ofstream fout(PROBLEM ".out");
    int m, s, c;
    fin >> m >> s >> c;
    vector<int> a(c);
    for (int i = 0; i < c; i++)
        fin >> a[i];
    sort(a.begin(), a.end());
    vector<int> b;
    for (int i = 1; i < c; i++)
        if (a[i] - a[i - 1] > 1)
            b.push_back(a[i] - a[i - 1] - 1);
    sort(b.rbegin(), b.rend());
    int total = a[c - 1] - a[0] + 1;
    for (int i = 0; i < min((int)b.size(), m - 1); i++)
        total -= b[i];
    fout << total << '\n';
    return 0;
}
