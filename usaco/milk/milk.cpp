/*
ID: dr.yste1
TASK: milk
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "milk"

int main() {
    ifstream fin(PROBLEM ".in");
    ofstream fout(PROBLEM ".out");
    int n, m;
    fin >> n >> m;
    vector<pair<int,int>> a(m);
    for (int i = 0; i < m; i++)
        fin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    int total = 0;
    for (int i = 0; i < m; i++) {
        int buy = min(a[i].second, n);
        total += a[i].first * buy;
        n -= buy;
    }
    fout << total << '\n';
    return 0;
}
