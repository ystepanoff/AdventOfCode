#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> f = { 0, 1 };
    for (int i = 2; i <= n; i++)
        f.push_back(f[i - 1] + f[i - 2]);
    for (int i = 1; i <= n; i++)
        f[i] += f[i - 1];
    cout << f[n] << '\n';
    return 0;
}
