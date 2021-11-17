#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> h(n), t(m);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < m; i++)
        cin >> t[i];
    multiset<int> s;
    for (int x : h)
        s.insert(-x);
    for (int x : t) {
        auto it = s.lower_bound(-x);
        if (it != s.end()) {
            cout << -(*it) << '\n';
            s.erase(it);
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}
