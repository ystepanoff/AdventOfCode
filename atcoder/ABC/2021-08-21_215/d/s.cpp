#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> sieve(m + 10, 0);
    vector<int> u(m + 10, 0);
    vector<int> pr;
    for (int i = 2; i <= m; i++)
        if (!sieve[i]) {
            pr.push_back(i);
            for (int j = 2; j * i <= m; j++)
                sieve[j * i] = 1;
        }
    for (int x : a) {
        for (int i = 0; i < pr.size() && pr[i] * pr[i] <= x; i++)
            if (!(x % pr[i])) {
                u[pr[i]] = 1;
                for (; !(x % pr[i]); x /= pr[i]);
            }
        if (x > 1 && x <= m)
            u[x] = 1;
    }
    vector<int> pr0;
    for (long long x : pr)
        if (u[x])
            pr0.push_back(x);
    vector<int> all;
    for (int i = 1; i <= m; i++) {
        bool good = true;
        for (int p : pr0)
            if (!(i % p)) {
                good = false;
                break;
            }
        if (good)
            all.push_back(i);
    }
    cout << all.size() << '\n';
    for (int x : all)
        cout << x << '\n';
    return 0;
}
