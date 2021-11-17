#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin >> m;
    vector<string> w(m);
    string t;
    getline(cin, t);
    for (int i = 0; i < m; i++)
        getline(cin, w[i]);
    int k;
    cin >> k;
    string s = "";
    vector<int> p0;
    getline(cin, t);
    for (int i = 0; i < k; i++) {
        getline(cin, t);
        s += t;
        p0.push_back(p0.size() ? p0.back() + t.length() : t.length());
    }
    s += '$';
    int n = s.length();
    vector<int> p(n), p_next(n), c(n), c_next(n);
    vector<int> cnt(n), pos(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j) {
        return s[i] < s[j];
    });
    c[p[0]] = 0;
    for (int i = 1; i < n; i++)
        c[p[i]] = c[p[i - 1]] + (int)(s[p[i - 1]] != s[p[i]]);
    k = 0;
    while ((1 << k) < n) {
        for (int &x : p) x = (x - (1 << k) + n) % n;
        fill(cnt.begin(), cnt.end(), 0);
        for (int x : c) cnt[x]++;
        pos[0] = 0;
        for (int i = 1; i < n; i++)
            pos[i] = pos[i - 1] + cnt[i - 1];
        for (int x : p) p_next[pos[c[x]]++] = x;
        p = p_next;
        c_next[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            pair<int,int> prev = { c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n] };
            pair<int,int> curr = { c[p[i]], c[(p[i] + (1 << k)) % n] };
            c_next[p[i]] = c_next[p[i - 1]] + (int)(prev != curr);
        }
        c = c_next;
        k++;
    } 
    int j = -1;
    for (string &t : w) {
        k = t.length();
        int l = 0, r = n;
        for (int mid = 0; mid < n; mid++) {
            string sm = s.substr(p[mid], k);
            int cmp = sm.compare(t);
            if (!cmp && (j == -1 || p[mid] < j)) {
                j = p[mid];
            }
            if (cmp < 0)
                l = mid;
            else 
                r = mid;
        }
    }
    if (j == -1) {
        cout << "Passed\n";
        return 0;
    }
    k = lower_bound(p0.begin(), p0.end(), j) - p0.begin();
    cout << k + 1 << " " << j + 1 - (k > 0 ? p0[k - 1] : 0) << '\n';
    return 0;
}
