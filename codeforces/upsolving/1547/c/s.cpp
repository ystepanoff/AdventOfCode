#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int k, n, m;
        cin >> k >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        int i = 0, j = 0;
        bool ok = true;
        vector<int> c;
        while (i < n && j < m) {
            if (a[i] == 0 && b[j] == 0) {
                c.push_back(0);
                c.push_back(0);
                i++;
                j++;
                k += 2;
            } else if (a[i] == 0) {
                c.push_back(0);
                i++;
                k++;
            } else if (b[j] == 0) {
                c.push_back(0);
                j++;
                k++;
            } else {
                if (a[i] <= k) {
                    c.push_back(a[i]);
                    i++;
                } else if (b[j] <= k) {
                    c.push_back(b[j]);
                    j++;
                } else {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            while (i < n) {
                if (a[i] <= k) {
                    c.push_back(a[i]);
                    k += (int)(a[i] == 0);
                    i++;
                } else {
                    ok = false;
                    break;
                }
            }
            while (j < m) {
                if (b[j] <= k) {
                    c.push_back(b[j]);
                    k += (int)(b[j] == 0);
                    j++;
                } else {
                    ok = false;
                    break;
                }
            }
        }
        if (!ok) {
            cout << "-1\n";
        } else {
            for (int x : c) cout << x << ' ';
            cout << '\n';
        }
    }
    return 0;
}
