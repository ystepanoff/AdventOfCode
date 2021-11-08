#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> bad(m + 1, 0);
    int total = 0;
    for (int j = 0; j < m - 1; j++) {
        for (int i = 1; i < n; i++)
            if (a[i][j] == 'X' && a[i - 1][j + 1] == 'X') total++;
        bad[j + 1] = total;
    }
    bad[m] = total;
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << (bad[x - 1] == bad[y - 1] ? "Yes" : "No") << '\n';
    }
    return 0;
}
