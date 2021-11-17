/*
ID: dr.yste1
TASK: money
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "money"

int main() {
    ifstream fin(PROBLEM ".in");
    ofstream fout(PROBLEM ".out");
    int n, m;
    fin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }
    vector<long long> dp(m + 1, 0);
    dp[0] = 1;
    for (int j = 0; j < n; j++) {
        for (int i = 1; i <= m; i++) {
            if (i >= a[j]) dp[i] += dp[i - a[j]];
        }
    }
    fout << dp[m] << '\n';
    fin.close();
    fout.close();
    return 0;
}
