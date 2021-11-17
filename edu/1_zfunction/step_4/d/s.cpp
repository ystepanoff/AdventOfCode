#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> t;
    int m = t.length(), n = 2 * m + 1;
    s = t + '$' + string(t.rbegin(), t.rend());
    vector<int> z(n, 0);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (r >= i)
            z[i] = min(z[i - l], r - i + 1);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    cout << *max_element(z.begin() + m, z.end()) << '\n';
    return 0;
}
