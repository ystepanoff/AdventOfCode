#include <bits/stdc++.h>
using namespace std;

vector<int> t;

void build(vector<int> &a, int x, int lx, int rx) {
    if (rx - lx == 1) {
        t[x] = a[lx];
        return;
    }
    int m = (lx + rx) >> 1;
    build(a, (x << 1) + 1, lx, m);
    build(a, (x << 1) + 2, m, rx);
    t[x] = t[(x << 1) + 1] + t[(x << 1) + 2];
}

void update(int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1) {
        t[x] = v;
        return;
    }
    int m = (lx + rx) >> 1;
    if (i < m) {
        update(i, v, (x << 1) + 1, lx, m);
    } else {
        update(i, v, (x << 1) + 2, m, rx);
    }
    t[x] = t[(x << 1) + 1] + t[(x << 1) + 2];
}

int kth_one(int k, int x, int lx, int rx) {
    if (rx - lx == 1) return k == 1 ? lx : -1; 
    int m = (lx + rx) >> 1;
    if (t[(x << 1) + 2] >= k) {
        return kth_one(k, (x << 1) + 2, m, rx);
    }
    return kth_one(k - t[(x << 1) + 2], (x << 1) + 1, lx, m);
}

int kth_zero(int k, int x, int lx, int rx) {
    if (rx - lx == 1) return k == 1 ? lx : -1;
    int m = (lx + rx) >> 1;
    if (rx - m - t[(x << 1) + 2] >= k) {
        return kth_zero(k, (x << 1) + 2, m, rx);
    }
    return kth_zero(k - (rx - m - t[(x << 1) + 2]), (x << 1) + 1, lx, m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n), c(n);
        vector<int> cnt(2, 0);
        for (int i = 0; i < n; i++) {
            cin >> c[i];
            c[i] %= 2;
            cnt[c[i]]++;
        }
        if (cnt[0] != cnt[1] + (n & 1) && cnt[1] != cnt[0] + (n & 1)) {
            cout << "-1\n";
            continue;
        }
        vector<vector<int>> cand;
        if (n & 1) {
            vector<int> b(n);
            for (int i = 0; i < n; i++) {
                b[i] = (i + (int)(cnt[0] + 1 == cnt[1])) % 2;
            }
            cand.push_back(b);
        } else {
            vector<int> b(n);
            for (int k = 0; k < 2; k++) {
                for (int i = 0; i < n; i++) {
                    b[i] = (i + k) % 2;
                }
                cand.push_back(b);
            }
        }
        int best = INT_MAX;
        for (auto &b : cand) {
            int x = cnt[0], y = cnt[1];
            int swaps = 0;
            for (int i = 0; i < n; i++) {
                a[i] = c[i];
            }
            t.assign(n << 2, 0);
            build(a, 0, 0, n);
            for (int i = 0; i < n; i++) {
                if (a[i] == 0 && b[i] == 0) x--;
                if (a[i] == 1 && b[i] == 1) y--;
                if (a[i] == 0 && b[i] == 1) {
                    int j = kth_one(y, 0, 0, n);
                    swap(a[i], a[j]);
                    update(i, 0, 0, 0, n);
                    update(j, 1, 0, 0, n);
                    swaps += j - i;
                    y--;
                }
                if (a[i] == 1 && b[i] == 0) {
                    int j = kth_zero(x, 0, 0, n);
                    swap(a[i], a[j]);
                    update(i, 1, 0, 0, n);
                    update(j, 0, 0, 0, n);
                    swaps += j - i;
                    x--;
                }
            }
            best = min(best, swaps);
        }
        cout << best << '\n';
    }
    return 0;
}
