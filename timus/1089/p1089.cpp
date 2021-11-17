#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<string> d;
    while (1) {
        string s;
        cin >> s;
        if (!s.compare("#"))
            break;
        d.push_back(s);
    }
    int total = 0;
    string s;
    getline(cin, s);
    while (getline(cin, s)) {
        string w = "";
        for (int i = 0; i <= s.length(); i++)
            if (i < s.length() && s[i] >= 'a' && s[i] <= 'z') {
                w += s[i];
            } else {
                if (w.length() > 0 && find(d.begin(), d.end(), w) == d.end()) {
                    for (string t : d)
                        if (t.length() == w.length()) {
                            int c = 0;
                            for (int j = 0; j < w.length(); j++)
                                if (t[j] != w[j])
                                    c++;
                            if (c == 1) {
                                for (int j = 0; j < w.length(); j++)
                                    s[i+j-w.length()] = t[j];
                                total++;
                                break;
                            }
                        }
                }
                w = "";
            }
        cout << s << '\n';
    }
    cout << total << '\n';
    return 0;
}
