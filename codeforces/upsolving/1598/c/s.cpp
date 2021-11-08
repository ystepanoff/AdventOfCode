#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        long long s = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
        }
        s <<= 1;
        if (s % n == 0) {
            s /= n;
            long long total = 0;
            map<long long,set<int>> mp;
            for (int i = 0; i < n; i++) {
                mp[a[i]].insert(i);
            }
            for (int i = 0; i < n; i++) {
                long long x = s - a[i];
                total += mp[x].size();
                if (mp[x].find(i) != mp[x].end()) total--;
            }
            cout << (total >> 1) << '\n';
        } else {
            cout << "0\n";
        }
    }
    return 0;
 }
