#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    int l = 0;
    for (int r = n - 1; r >= 0; r--) {
        while (l < r && a[l].first + a[r].first < x) l++;
        if (l < r && a[l].first + a[r].first == x) {
            cout << a[l].second << ' ' << a[r].second << '\n';
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
