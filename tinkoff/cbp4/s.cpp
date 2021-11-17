#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> seg(n + 2, 0);
    vector<pair<int,int>> queries;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        seg[l] += 1;
        seg[r + 1] += -1;
        queries.emplace_back(l, r);
    }
    for (int i = 1; i <= n; i++) 
        seg[i] += seg[i - 1];
    vector<vector<int>> pos(q + 1);
    for (int i = 1; i <= n; i++)
        pos[seg[i]].push_back(i);
    int j = 0;
    sort(a.rbegin(), a.rend());
    vector<long long> b(n + 1, 0);
    for (int i = q; i >= 1; i--)
        for (int x : pos[i])
            b[x] = a[j++];
    for (int i = 1; i <= n; i++)
        b[i] += b[i - 1];
    long long total = 0;
    for (auto p : queries) {
        total += b[p.second] - b[p.first - 1];
    }
    cout << total << '\n';
    return 0;
}
