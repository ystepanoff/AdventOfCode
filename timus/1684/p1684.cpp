#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length(), m = s2.length();
    string s = s1 + '$' + s2;
    vector<int> z(n + m + 1, 0);
    for (int i = 1, l = 0, r = 0; i <= n + m; i++) {
        if (r >= i)
            z[i] = min(z[i - l], r - i + 1);
        while (i + z[i] <= n + m && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    vector<pair<int,int>> p;
    bool yes = false;
    int last = n + m + 1;
    for (int i = n + m; i > n; i--)
        if (z[i] > 0 && i + z[i] >= last) {
            p.push_back({i, last - i});
            last = i;
        }
    reverse(p.begin(), p.end());
    string t = "";
    for (auto q : p)
        t += s.substr(q.first, q.second);
    if (t.compare(s2) != 0) {
        cout << "Yes\n";
        return 0;
    }
    cout << "No\n";
    for (auto q : p)
        cout << s.substr(q.first, q.second) << ' ';
    cout << '\n';
    return 0;
}
