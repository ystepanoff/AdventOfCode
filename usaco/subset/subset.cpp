/*
ID: dr.yste1
TASK: subset
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "subset"

int main() {
    ifstream fin(PROBLEM ".in");
    ofstream fout(PROBLEM ".out");
    int n;
    fin >> n;
    int s = n * (n + 1) / 2;
    if (s % 2) {
        fout << "0\n";
        return 0;
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(s + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= s; j++) {
            dp[i][j] += dp[i - 1][j];
            if (j >= i) dp[i][j] += dp[i - 1][j - i];
        }
    fout << dp[n][s / 2] / 2 << '\n';
    fin.close();
    fout.close();
    return 0;
}
