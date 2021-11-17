#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s, p;
    cin >> s >> p;
    int n = s.length(), m = p.length();
    if (n != m) {
        cout << "No\n";
        return 0;
    }
    string t = p + s;
    vector<int> z(n + n, 0);
    for (int i = 1, l = 0, r = 0; i < n + n; i++) {
        if (r >= i)
            z[i] = min(z[i - l], r - i + 1);
        while (i + z[i] < n + n && t[z[i]] == t[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    int k = -1;
    for (int i = n; i < n + n; i++)
        if (i + z[i] == n + n) {
            k = z[i];
            break;
        }
    if (k == -1) {
        cout << "No\n";
        return 0;
    }
    string a = s.substr(n - k);
    string b = s.substr(0, n - k);
    if (!p.compare(a + string(b.rbegin(), b.rend()))) {
        cout << "Yes\n" << n - k << '\n';
    } else {
        cout << "No\n";
    }
    return 0;
}
