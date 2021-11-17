#include <bits/stdc++.h>
using namespace std;

bool check(char a, char b) {
    return (a == '(' && b == ')') || (a == '[' && b == ']');
}

vector<vector<string>> cache;

string dp(string &s, int l, int r) {
    if (cache[l][r].compare("*") != 0) return cache[l][r];
    if (l == r) {
        if (s[l] == '(' || s[l] == ')') cache[l][r] = "()";
        if (s[l] == '[' || s[l] == ']') cache[l][r] = "[]";
    } else if (l + 1 == r) {   
        if (s[l] == '(' && s[r] == '(') cache[l][r] = "()()";
        if (s[l] == '(' && s[r] == ')') cache[l][r] = "()";
        if (s[l] == '(' && s[r] == '[') cache[l][r] = "()[]";
        if (s[l] == '(' && s[r] == ']') cache[l][r] = "()[]";
        if (s[l] == ')' && s[r] == '(') cache[l][r] = "()()";
        if (s[l] == ')' && s[r] == ')') cache[l][r] = "()()";
        if (s[l] == ')' && s[r] == '[') cache[l][r] = "()[]";
        if (s[l] == ')' && s[r] == ']') cache[l][r] = "()[]";
        if (s[l] == '[' && s[r] == '(') cache[l][r] = "[]()";
        if (s[l] == '[' && s[r] == ')') cache[l][r] = "[]()";
        if (s[l] == '[' && s[r] == '[') cache[l][r] = "[][]";
        if (s[l] == '[' && s[r] == ']') cache[l][r] = "[]";
        if (s[l] == ']' && s[r] == '(') cache[l][r] = "[]()";
        if (s[l] == ']' && s[r] == ')') cache[l][r] = "[]()";
        if (s[l] == ']' && s[r] == '[') cache[l][r] = "[][]";
        if (s[l] == ']' && s[r] == ']') cache[l][r] = "[][]";
    } else {
        if (check(s[l], s[r])) {
            string best = s[l] + dp(s, l + 1, r - 1) + s[r];
            for (int k = l; k < r; k++) {
                string t = dp(s, l, k) + dp(s, k + 1, r);
                if (t.length() < best.length()) {
                    best = t;
                }
            }
            cache[l][r] = best;
        } else {
            int best = -1;
            string beststr;
            for (int k = l; k < r; k++) {
                string t = dp(s, l, k) + dp(s, k + 1, r);
                if (best == -1 || t.length() < best) {
                    best = t.length();
                    beststr = t;
                }
            }
            cache[l][r] = beststr;
        }
    }
    return cache[l][r];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    if (n == 0) {
        cout << '\n';
        return 0;
    }
    cache.assign(n, vector<string>(n, "*"));
    cout << dp(s, 0, n - 1) << '\n';
    return 0;
}
