#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int l;
        cin >> l;
        vector<int> a(l);
        for (int j = 0; j < l; j++) {
            cin >> a[j];
        }
        for (int x = 0; x < l; x++) {
            for (int y = 0; y < l; y++) {
                if (x != y) g[a[x]].push_back(a[y]);
            }
        }
    }
    int k;
    cin >> k;
    vector<int> money(k), stop(k), free(k);
    for (int i = 0; i < k; i++) {
        cin >> money[i] >> stop[i] >> free[i];
    }
    int beststop = -1, best = -1;
    for (int v = 1; v <= n; v++) {
        vector<bool> u(n + 1, false);
        vector<int> d(n + 1, 0);
        vector<int> q;
        u[v] = true;
        q.push_back(v);
        for (int i = 0; i < q.size(); i++) {
            for (int x : g[q[i]]) if (!u[x]) {
                u[x] = true;
                d[x] = d[q[i]] + 1;
                q.push_back(x);
            }
        }
        int total = 0;
        for (int i = 0; i < k; i++) {
            if (!u[stop[i]]) {
                total = -1;
                break;
            }
            if (free[i]) continue;
            if (money[i] >= d[stop[i]] * 4) {
                total += d[stop[i]] * 4;
            } else {
                total = -1;
                break;
            }
        }
        if (total != -1) {
            if (best == -1 || total < best) {
                beststop = v;
                best = total;
            }
        }
    }
    if (best != -1) {
        cout << beststop << ' ' << best << '\n';
    } else {
        cout << "0\n";
    }
    return 0;
}
