#include <bits/stdc++.h>
using namespace std;

string t = "Sandro";

int cost(string s) {
    int c = 0;
    for (int i = 0; i < 6; i++) {
        if (s[i] == t[i]) continue;
        if (s[i] >= 'a' && s[i] <= 'z') {
            if (t[i] >= 'A' && t[i] <= 'Z') {
                s[i] = toupper(s[i]);
                c += 5;
            }
            if (s[i] != t[i]) c += 5;
        } else {
            if (t[i] >= 'a' && t[i] <= 'z') {
                s[i] = tolower(s[i]);
                c += 5;
            }
            if (s[i] != t[i]) c += 5;
        }
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    int best = 1e9;
    for (int i = 0; i + 6 <= n; i++)
        best = min(best, cost(s.substr(i, 6)));
    cout << best << '\n';
    return 0;
}
