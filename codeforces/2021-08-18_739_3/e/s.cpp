#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string t;
        cin >> t;
        int n = t.length();
        string letters = "";
        vector<int> cnt(256, 0);
        for (int i = n - 1; i >= 0; i--) {
            if (cnt[t[i]] == 0)
                letters = t[i] + letters;
            cnt[t[i]]++;
        }
        int steps = letters.length();
        int l = 0;
        for (int i = 0; i < steps; i++)
            l += cnt[letters[steps - i - 1]] / (steps - i);
        string s = t.substr(0, l);
        string st = s, p = s;
        for (char c : letters) {
            string curr = "";
            for (char d : st)
                if (d != c)
                    curr += d;
            st = curr;
            p += curr;
        }
        if (!t.compare(p)) {
            cout << s << ' ' << letters << '\n';
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}
