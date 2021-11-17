#include <bits/stdc++.h>
using namespace std;

void count_sort(vector<int> &p, vector<int> &c) {
    int n = p.size();
    vector<int> cnt(n, 0), pos(n, 0), p_new(n);
    for (int x : c)
        cnt[x]++;
    for (int i = 1; i < n; i++)
        pos[i] = pos[i - 1] + cnt[i - 1];
    for (int x : p)
        p_new[pos[c[x]]++] = x;
    p = p_new;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    s += '$';
    int n = s.length();
    vector<int> p(n), c(n), c_new(n);
    iota(p.begin(), p.end(), 0);
    for (int i = 0; i < n; i++)
        c[i] = (int)(s[i] - 'a');
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
        count_sort(p, c);
        c_new[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            c_new[p[i]] = c_new[p[i - 1]];
            pair<int, int> prev = make_pair(c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]);
            pair<int, int> curr = make_pair(c[p[i]], c[(p[i] + (1 << k)) % n]);
            if (prev != curr)
                c_new[p[i]]++;
        }
        c = c_new;
        k++;
    }
    for (int i = 0; i < n; i++) {
        cout << p[i];
        if (i < n - 1)
            cout << ' ';
    }
    cout << '\n';
    return 0;
}
