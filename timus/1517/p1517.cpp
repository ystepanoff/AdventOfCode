#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin >> m;
    string s1, s2;
    cin >> s1 >> s2;
    string s = s1 + '#' + s2 + '!';
    int n = s.length();
    vector<int> p(n), c(n), p_new(n), c_new(n);
    vector<int> cnt(n), pos(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j) {
        return s[i] < s[j];
    });
    c[p[0]] = 0;
    for (int i = 1; i < n; i++) {
        c[p[i]] = c[p[i - 1]];
        if (s[p[i]] != s[p[i - 1]])
            c[p[i]]++;
    }
    int k = 0;
    while ((1 << k) < n) {
        for (int i = 0; i < n; i++)
            p[i] = (p[i] - (1 << k) + n) % n;
        fill(cnt.begin(), cnt.end(), 0);
        for (int x : c)
            cnt[x]++;
        pos[0] = 0;
        for (int i = 1; i < n; i++)
            pos[i] = pos[i - 1] + cnt[i - 1];
        for (int x : p)
            p_new[pos[c[x]]++] = x;
        p = p_new;
        c_new[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            pair<int,int> prev = { c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n] };
            pair<int,int> curr = { c[p[i]], c[(p[i] + (1 << k)) % n] };
            c_new[p[i]] = c_new[p[i - 1]];
            if (prev != curr)
                c_new[p[i]]++;
        }
        c = c_new;
        k++;
    }
    k = 0;
    vector<int> lcp(n, 0);
    for (int i = 0; i < n - 1; i++) {
        int j = p[c[i] - 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k])
            k++;
        lcp[c[i]] = k;
        k = max(k - 1, 0);
    }
    int best = 0;
    string r = "";
    for (int i = 1; i < n; i++)
        if ((p[i] < m && p[i - 1] > m) || (p[i] > m && p[i - 1] < m))
            if (lcp[i] > best) {
                best = lcp[i];
                r = s.substr(p[i], lcp[i]);
            }
    cout << r << '\n';
    return 0;
}

