#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        vector<int> p(n + 1), q(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> p[i];
        for (int i = 1; i <= n; i++)
            q[p[i]] = i;
        for (int i = 1; i <= n; i++)
            cout << q[i] << ' ';
        cout << '\n';
    }
    return 0;
}
