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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int m = n >> 1;
        bool same = false;
        map<int,int> cnt;
        for (int i = 1; i < n; i++) {
            cnt[a[i]]++;
            if (cnt[a[i]] >= m) {
                same = true;
                break;
            }
        }
        if (same) {
            cout << "-1\n";
        } else {
            int best = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    int d = abs(a[i] - a[j]);
                    int mn = min(a[i], a[j]);
                    vector<int> divs;
                    for (int c = 1; c * c <= d; c++) {
                        if (!(d % c)) {
                            divs.push_back(c);
                            divs.push_back(d / c);
                        }
                    }
                    for (int k : divs) {
                        int c = 0;
                        for (int x : a) {
                            if (x >= mn && (x - mn) % k == 0) {
                                c++;
                            }
                        }
                        if (c >= m) {
                            best = max(best, k);
                        }
                    }
                }
            }
            cout << best << '\n';
        }
    }
    return 0;
}
