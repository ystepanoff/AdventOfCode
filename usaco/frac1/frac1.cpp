/*
ID: dr.yste1
TASK: frac1
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "frac1"

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ifstream fin(PROBLEM ".in");
    ofstream fout(PROBLEM ".out");
    int n;
    fin >> n;
    vector<pair<int,int>> a;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= i; j++)
            if (gcd(i, j) == 1)
                a.push_back(make_pair(j, i));
    sort(a.begin(), a.end(), [](const pair<int,int> &a, const pair<int,int> &b) {
        return a.first * b.second < b.first * a.second;
    });
    for (auto p : a)
        fout << p.first << '/' << p.second << '\n';
    fin.close();
    fout.close();
    return 0;
}
