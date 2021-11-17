#include <bits/stdc++.h>
using namespace std;

unordered_map<long long,bool> u;

void gen(vector<long long> &b, int n, long long curr, int d1, int d2) {
    if (n == 0)
        return;
    if (!u[curr]) {
        b.push_back(curr);
        u[curr] = true;
    }
    gen(b, n - 1, curr * 10 + d1, d1, d2);
    gen(b, n - 1, curr * 10 + d2, d1, d2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<long long>> b(2);
    long long x = 0;
    for (int i = 0; i < 11; i++) {
        x = x * 10 + 1;
        for (long long d = 1; d <= 9; d++)
            b[0].push_back(x * d);
    }
    for (int d1 = 0; d1 <= 9; d1++)
        for (int d2 = 0; d2 <= 9; d2++)
            gen(b[1], 11, 0, d1, d2);
    for (auto& a : b)
        sort(a.begin(), a.end());
    int tt;
    cin >> tt;
    while (tt--) {
        long long n;
        int k;
        cin >> n >> k;
        k--;
        cout << *lower_bound(b[k].begin(), b[k].end(), n) << '\n';
    }
    return 0;
}
