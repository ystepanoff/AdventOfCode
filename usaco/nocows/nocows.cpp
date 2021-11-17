/*
ID: dr.yste1
TASK: nocows
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "nocows"

int main() {
    ifstream fin(PROBLEM ".in");
    ofstream fout(PROBLEM ".out");
    int mod = 9901;
    int k, n;
    fin >> k >> n;
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
        dp[1][i] = 1;
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= n; j++)
            for (int x = 0; x < i; x++)
                dp[i][j] = (dp[i][j] + dp[x][j - 1] * dp[i - x - 1][j - 1]) % mod;
    fout << (dp[k][n] - dp[k][n - 1] + mod) % mod << '\n';
    fin.close();
    fout.close();
    return 0;
}
