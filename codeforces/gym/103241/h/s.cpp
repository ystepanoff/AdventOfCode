#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    const long long mod = 1e9 + 7;
    int n;
    cin >> n;
    vector<long long> fact(n + 1, 1);
    for (int i = 1; i <= n; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++) {
        string s;
        int c;
        cin >> s >> c;
        cnt[c]++;
    }
    long long r = 1;
    for (int i = 1; i <= n; i++)
        r = (r * fact[cnt[i]]) % mod;
    cout << r << '\n';
    return 0;

}
