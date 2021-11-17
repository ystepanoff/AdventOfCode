#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end(), [](auto &a, auto &b) {
        return a.second < b.second;
    });
    int last = -1, total = 0;
    for (int i = 0; i < n; i++)
        if (last == -1 || (a[i].first >= a[last].second)) {
            total += 1;
            last = i;
        }
    cout << total << '\n';
    return 0;
}
