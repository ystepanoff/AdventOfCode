#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int m = s.length();
    s = s + s;
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
    int pos = 1;
    for (int i = 1; i < m; i++)
        if (i + z[i] < n && s[i + z[i]] < s[z[i]])
            pos++;
    cout << pos << '\n';
    return 0;
}
