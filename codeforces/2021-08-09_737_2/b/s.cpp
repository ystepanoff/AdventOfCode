#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int,int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        int c = 1;
        for (int i = 1; i < n; i++)
            if (a[i].second != a[i - 1].second + 1)
                c++;
        cout << (c <= k ? "Yes\n" : "No\n");
    }
    return 0;
}
