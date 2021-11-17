#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s, p;
    cin >> s >> p;
    int n = s.length(), m = p.length();
    s = p + '$' + s;
    vector<int> z(n + m + 1, 0);
    int l = 0, r = 0;
    for (int i = 1; i <= n + m; i++) {
        if (r >= i)
            z[i] = min(z[i - l], r - i + 1);
        while (i + z[i] <= n + m && s[i + z[i]] == s[z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    int total = 0;
    for (int i = m; i <= n + m; i++)
        if (z[i] == m)
            total++;
    cout << total << '\n';
    return 0;
}
