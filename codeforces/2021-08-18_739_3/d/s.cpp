#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<string> p2;
    vector<pair<string,int>> p2s;
    for (long long i = 0; i < 63; i++) {
        string s = to_string(1LL << i);
        string p = "";
        p2.push_back(s);
        for (int i = 0; i < s.length(); i++) {
            p += s[i];
            p2s.push_back({p, s.length()});
        }
    }
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        int n = s.length();
        int best = 1e9;
        for (string& p : p2)
            best = min(best, (int)(n + p.length()));
        for (auto& pp : p2s) {
            string p = pp.first;
            int k = pp.second;
            int m = p.length(); 
            int j = 0;
            for (int i = 0; i < n; i++)
                if (j < m && s[i] == p[j])
                    j++;
            if (j == m)
                best = min(best, n - m + k - m);
        }
        cout << best << '\n';
    }
    return 0;
}
