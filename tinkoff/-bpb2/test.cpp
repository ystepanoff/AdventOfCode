#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,bool>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = false;
    }
    reverse(a.begin(), a.end());
    for (int i = 0; i < 2 * n; i++) {
        auto p = a.back();
        a.pop_back();
        p.second = true;
        a.insert(a.begin() + p.first, p);
    }
    int total = 0;
    for (int i = 0; i < n; i++) {
        if (!a[i].second) total++;
    }
    cout << total << '\n';
    return 0;
}
