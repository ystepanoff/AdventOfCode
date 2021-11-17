#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, total = 0;
    for (int j = 0; j < m; j++) {
        while (i < n && a[i] + k < b[j]) i++;
        if (i < n && abs(b[j] - a[i]) <= k) {
            total++;
            i++;
        }
    }
    cout << total << '\n';
    return 0;
}
