#include <bits/stdc++.h>
using namespace std;

string check(string &s, string &p) {
    int n = s.length(), m = p.length();
    string t = p + '$' + s;
    vector<int> z(n + m + 1, 0);
    for (int i = 1, l = 0, r = 0; i <= n + m; i++) {
        if (r >= i)
            z[i] = min(z[i - l], r - i + 1);
        while (i + z[i] <= n + m && t[z[i]] == t[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
        if (z[i] == m)
            return s;
    }
    for (int i = m; i <= n + m; i++)
        if (i + z[i] == n + m + 1)
            return s + p.substr(z[i]);
    return s + p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s, p;
        cin >> s >> p;
        string a = check(s, p);
        string b = check(p, s);
        if (a.length() > b.length())
            a = b;
        cout << a << '\n';
    }
    return 0;
}
