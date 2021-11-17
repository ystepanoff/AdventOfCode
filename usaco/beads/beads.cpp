/*
ID: dr.yste1
TASK: beads
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int n;
    fin >> n;
    string s;
    fin >> s;
    s = s + s + s;
    int best = 0;
    for (int i = n; i < n + n; i++) {
        int curr = 0;
        int cr = 0, cb = 0;
        for (int l = i; s[l] == 'w' || s[l] == 'r'; l--) cr++;
        for (int l = i; s[l] == 'w' || s[l] == 'b'; l--) cb++;
        curr += max(cr, cb);
        cr = 0, cb = 0;
        for (int r = i + 1; r < n + n + n && (s[r] == 'w' || s[r] == 'r'); r++) cr++;
        for (int r = i + 1; r < n + n + n && (s[r] == 'w' || s[r] == 'b'); r++) cb++;
        curr += max(cr, cb);
        best = max(best, min(n, curr));
    }
    fout << best << '\n';
    return 0;
}
