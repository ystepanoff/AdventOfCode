#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    s += '$';
    int n = s.length();
    vector<int> p(n), c(n);
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
        vector<pair<int,int>> a(n);
        for (int i = 0; i < n; i++)
            a[i] = make_pair(c[i], c[(i + (1 << k)) % n]);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(), [&](int i, int j) {
            return a[i] < a[j];
        });
        c[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            c[p[i]] = c[p[i - 1]];
            if (a[p[i]] != a[p[i - 1]])
                c[p[i]]++;
        }
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
