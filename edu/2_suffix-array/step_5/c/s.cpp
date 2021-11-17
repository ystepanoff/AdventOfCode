#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    s += '$';
    int n = s.length();
    vector<int> p(n), p_new(n), cnt(n), pos(n);
    vector<int> c_curr(n), c_next(n);
    vector<vector<int>> c;
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j) {
        return s[i] < s[j];    
    });
    c_curr[p[0]] = 0;
    for (int i = 1; i < n; i++) {
        c_curr[p[i]] = c_curr[p[i - 1]];
        if (s[p[i]] != s[p[i - 1]])
            c_curr[p[i]]++;
    }
    c.push_back(c_curr);
    int k = 0;
    while ((1 << k) < n) {
        for (int i = 0; i < n; i++)
            p[i] = (p[i] - (1 << k) + n) % n;
        fill(cnt.begin(), cnt.end(), 0);
        for (int x : c_curr)
            cnt[x]++;
        pos[0] = 0;
        for (int i = 1; i < n; i++)
            pos[i] = pos[i - 1] + cnt[i - 1];
        for (int x : p)
            p_new[pos[c_curr[x]]++] = x;
        p = p_new;
        c_next[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            pair<int,int> prev = { c_curr[p[i - 1]], c_curr[(p[i - 1] + (1 << k)) % n] };
            pair<int,int> curr = { c_curr[p[i]], c_curr[(p[i] + (1 << k)) % n] };
            c_next[p[i]] = c_next[p[i - 1]];
            if (prev != curr)
                c_next[p[i]]++;
        }
        c_curr = c_next;
        c.push_back(c_curr);
        k++;
    }
    int m;
    cin >> m;
    vector<pair<int,int>> pairs(m);
    for (int i = 0; i < m; i++)
        cin >> pairs[i].first >> pairs[i].second;
    sort(pairs.begin(), pairs.end(), [&c](auto &p1, auto &p2) {
        int i1 = p1.first, j1 = p1.second;
        int i2 = p2.first, j2 = p2.second;
        int l1 = j1 - i1 + 1, l2 = j2 - i2 + 1;
        int l = min(l1, l2);
        int k = 0;
        while ((1 << k) <= l)
            k++;
        k--;
        if (k >= c.size())
            k = c.size() - 1;
        pair<int,int> a = { c[k][i1 - 1], c[k][i1 + l - (1 << k) - 1] };
        pair<int,int> b = { c[k][i2 - 1], c[k][i2 + l - (1 << k) - 1] };
        if (a != b)
            return a < b;
        if (l1 != l2)
            return l1 < l2;
        return p1 < p2;
    });
    for (auto& q : pairs)
        cout << q.first << ' ' << q.second << '\n';
    return 0;
}
