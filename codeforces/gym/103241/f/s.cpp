#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<string,int>> b(n);
    for (auto& p : b)
        cin >> p.first >> p.second;
    sort(b.begin(), b.end(), [&](auto &a, auto &b) {
        return a.first[0] < b.first[0] || (a.first[0] == b.first[0] && a.second < b.second);
    });
    for (auto& p : b)
        cout << p.first << '\n';
    return 0;
}
