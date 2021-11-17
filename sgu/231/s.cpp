#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<bool> pr(n + 1, true);
    vector<int> p;
    pr[0] = pr[1] = false;
    for (int i = 2; i <= n; i++)
        if (pr[i]) {
            p.push_back(i);
            for (int j = i + i; j <= n; j += i)
                pr[j] = false;
        }
    int total = 0;
    for (int i = 0; i < p.size(); i++)
        if (2 + p[i] <= n && pr[2 + p[i]])
            total++;
    cout << total << '\n';
    for (int i = 0; i < p.size(); i++)
        if (2 + p[i] <= n && pr[2 + p[i]])
            cout << "2 " << p[i] << '\n';
    return 0;
}
