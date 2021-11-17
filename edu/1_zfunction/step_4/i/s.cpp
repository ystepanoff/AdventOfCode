#include <bits/stdc++.h>
using namespace std;

vector<int> zfunc(string &s) {
    int n = s.length();
    vector<int> z(n, 0);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (r >= i)
            z[i] = min(z[i - l], r - i + 1);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s, p;
    int k;
    cin >> s >> p;
    cin >> k;
    string ta = p + '$' + s;
    string tb = string(p.rbegin(), p.rend()) + '$' + string(s.rbegin(), s.rend());
    auto za = zfunc(ta), zb = zfunc(tb);
    vector<int> r;
    for (int i = p.size() + 1; i < za.size() - p.size() + 1; i++)
        if (za[i] + zb[ta.size() - i + 1] + k >= p.size())
            r.push_back(i - p.size());
    cout << r.size() << '\n';
    for (int x : r)
        cout << x << ' ';
    cout << '\n';
    return 0;
}
