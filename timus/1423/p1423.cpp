#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s, p;
    cin >> s >> p;
    if (!s.compare(p)) {
        cout << "0\n";
        return 0;
    }
    string t = p + '$' + s;
    int m = t.length();
    vector<int> z(m, 0);
    for (int i = 1, l = 0, r = 0; i < m; i++) {
        if (r >= i)
            z[i] = min(z[i - l], r - i + 1);
        while (i + z[i] < m && t[z[i]] == t[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    int r = -1;
    for (int i = n; i < m; i++)
        if (i + z[i] == m) {
            string q = p.substr(z[i]) + p.substr(0, z[i]);
            if (!s.compare(q)) {
                r = z[i];
                break;
            }
        }
    cout << r << '\n';
    return 0;
}
