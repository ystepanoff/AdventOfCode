#include <bits/stdc++.h>
using namespace std;

bool can(vector<pair<long long,long long>> &b, long long s) {
    for (auto& p : b) {
        if (s <= p.second)
            return false;
        s += p.first;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<pair<long long,long long>> b(n);
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            vector<int> a(k);
            for (int j = 0; j < k; j++) {
                cin >> a[j];
                a[j] -= j;
            }
            b.emplace_back(k, *max_element(a.begin(), a.end()));
        }
        sort(b.begin(), b.end(), [&](auto &a, auto &b) {
            return a.second < b.second || (a.second == b.second && a.first > b.first);
        });
        long long l = 0, r = 1e18;
        while (r - l > 1) {
            long long m = (l + r) >> 1;
            if (can(b, m))
                r = m;
            else
                l = m;
        }
        cout << r << '\n';
    }
    return 0;
}
