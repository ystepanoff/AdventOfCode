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
    stable_sort(a.begin(), a.end(), [&](const pair<int,int> &a, const pair<int,int> &b) {
        return a.second > b.second;
    });
    for (int i = 0; i < n; i++)
        cout << a[i].first << ' ' << a[i].second << '\n';
    return 0;
}
