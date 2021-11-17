/*
ID: dr.yste1
TASK: lamps
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "lamps"

set<string> cand;

void gen(int c, string curr) {
    if (c == 0) {
        cand.insert(curr);
        return;
    }
    int n = curr.length();
    string t[4];
    for (int i = 0; i < 4; i++) {
        t[i] = curr;
    }
    for (int i = 0; i < n; i++) {
        t[0][i] = (1 - (t[0][i] - '0')) + '0';
        if (!(i & 1)) t[1][i] = (1 - (t[1][i] - '0')) + '0';
        if (i & 1) t[2][i] = (1 - (t[2][i] - '0')) + '0';
        if ((i + 1) % 3 == 1) t[3][i] = (1 - (t[3][i] - '0')) + '0';
    }
    for (int i = 0; i < 4; i++) {
        gen(c - 1, t[i]);
    }
}

int main() {
    ifstream fin(PROBLEM ".in");
    ofstream fout(PROBLEM ".out");
    int n, c;
    fin >> n >> c;
    if (c & 1) c = min(3, c);
    else c = min(4, c);
    string mask = string(n, '*');
    int v;
    while (fin >> v) {
        if (v == -1) break;
        mask[v - 1] = '1';     
    }
    while (fin >> v ) {
        if (v == -1) break;
        mask[v - 1] = '0';
    }
    gen(c, string(n, '1'));
    bool found = false;
    for (auto &s : cand) {
        bool match = true;
        for (int i = 0; i < n; i++) {
            if (mask[i] != '*' && s[i] != mask[i])
                match = false;
        }
        if (match) {
            fout << s << '\n';
            found = true;
        }
    }
    if (!found) fout << "IMPOSSIBLE\n";
    fin.close();
    fout.close();
    return 0;
}
