#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
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
        c[p[i]] = c[p[i - 1]] + (int)(s[p[i]] != s[p[i - 1]]);
    int k = 0;
    while ((1 << k) < n && c[p[n - 1]] != n - 1) {
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
    for (int i = 0; i < n; i++)
        cout << p[i] << ' ' << s.substr(p[i], n - p[i]) << '\n';
    k = 0;
    vector<int> lcp(n);
    for (int i = 0; i < n; i++) {
        int j = p[c[i] - 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k])
           k++;
        lcp[c[i]] = k;
        k = max(k - 1, 0); 
    }
    for (int i = 1; i < n; i++)
        cout << lcp[i] << ' ';
    cout << '\n';
    return 0;
}
