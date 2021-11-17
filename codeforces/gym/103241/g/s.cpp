#include <bits/stdc++.h>
using namespace std;

string get_right(vector<string> &vars, string &s) {
    for (auto &t : vars)
        if (s.length() == t.length()) {
            int d = 0;
            for (int i = 0; i < s.length(); i++)
                if (s[i] != t[i])
                    d++;
            if (d == 1)
                return t;
        }
    return "";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<string> sizes = { "small", "medium", "large" };
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<string> a(n);
        for (auto& s : a)
            cin >> s;
        string s, t;
        cin >> s >> t;
        cout << get_right(sizes, s) << ' ' << get_right(a, t) << '\n';
    }
    return 0;
}
