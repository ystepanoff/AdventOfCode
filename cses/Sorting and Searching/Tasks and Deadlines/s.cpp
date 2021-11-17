#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    long long total = 0, curr = 0;
    for (int i = 0; i < n; i++) {
        curr += a[i].first;
        total += a[i].second - curr;
    }
    cout << total << '\n';
    return 0;
}
