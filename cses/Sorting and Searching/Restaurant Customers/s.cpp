#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,bool>> a(n << 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i + n].first;
        a[i].second = true;
        a[i + n].second = false;
    }
    sort(a.begin(), a.end());
    int best = 0, curr = 0;
    for (int i = 0; i < (n << 1); i++)
        if (a[i].second) {
            curr++;
            best = max(best, curr);
        } else {
            curr--;
        }
    cout << best << '\n';
    return 0;
}
