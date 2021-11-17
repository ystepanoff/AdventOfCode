/*
ID: dr.yste1
TASK: prefix
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "prefix"

int main() {
    ifstream fin(PROBLEM ".in");
    ofstream fout(PROBLEM ".out");
    vector<string> a;
    while (1) {
        string s;
        fin >> s;
        if (!s.compare(".")) break;
        a.push_back(s);
    }
    string p;
    string s = "";
    while (fin >> p) {
        s += p;
    }
    int n = s.length();
    vector<int> dp(n + 1, false);
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
        for (string &t : a) {
            int j = t.length();
            if (i >= j && !t.compare(s.substr(i - j, j)))
                dp[i] |= dp[i - j];
        }
    }
    for (int i = n; i >= 0; i--) {
        if (dp[i]) {
            fout << i << '\n';
            break;
        }
    }
    fin.close();
    fout.close();
    return 0;
}
