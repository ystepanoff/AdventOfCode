#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e16;

int main() {
    int N = 2020;
    vector< vector< vector<long long> > > dcnt(N + 1, vector< vector<long long> >(10 * N + 1, vector<long long>(10, 0)));
    vector< vector< vector<long long> > > dsum(N + 1, vector< vector<long long> >(10 * N + 1, vector<long long>(10, 0)));
    dcnt[0][0][0] = 1;
    for (int n = 0; n < N; n++) {
        for (int s = 0; s <= 9 * n; s++) {
            for (int md = 0; md < 10; md++) {
                for (int d = 0; d < 10; d++) {
                    (dcnt[n + 1][s + d][max(md, d)] += dcnt[n][s][md]) %= MOD;
                    (dsum[n + 1][s + d][max(md, d)] += dsum[n][s][md] * 10 + dcnt[n][s][md] * d) %= MOD;
                }
            }
        }
    }
    long long total = 0;
    for (int md = 0; md < 10; md++) {
        (total += dsum[N][2 * md][md]) %= MOD;
    }
    cout << total << '\n';
    return 0;
}
