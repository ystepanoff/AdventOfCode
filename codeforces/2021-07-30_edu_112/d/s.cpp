#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<vector<int>> r;
    vector<int> p(n, 0);
    for (char a : "abc")
        for (char b : "abc")
            for (char c : "abc")
                if (a != b && b != c && a != c) {
                    for (int i = 0; i < n; i++) {
                        char ch = string({ a, b, c })[i % 3];
                        p[i] = (int)(ch != s[i]);
                        if (i > 0)
                            p[i] += p[i - 1];
                    }
                    r.push_back(p);
                }
    while (m--) {
        int i, j, best = 1e9;
        cin >> i >> j;
        i--, j--;
        for (auto& p : r)
            best = min(best, p[j] - (i > 0 ? p[i - 1] : 0));
        cout << best << '\n';
    }
    return 0;
}
