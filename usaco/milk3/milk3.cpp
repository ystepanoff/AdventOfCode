/*
ID: dr.yste1
TASK: milk3
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "milk3"

bool seen[25][25][25];
vector<int> res;
int A, B, C;

void dfs(int a, int b, int c) {
    if (seen[a][b][c])
        return;
    seen[a][b][c] = true;
    if (!a && find(res.begin(), res.end(), c) == res.end()) 
        res.push_back(c);
    if (a > 0) {
        if (b + a <= B) dfs(0, b + a, c); else dfs(a - (B - b), B, c);
        if (c + a <= C) dfs(0, b, c + a); else dfs(a - (C - c), b, C);
    }
    if (b > 0) {
        if (a + b <= A) dfs(a + b, 0, c); else dfs(A, b - (A - a), c);
        if (c + b <= C) dfs(a, 0, c + b); else dfs(a, b - (C - c), C);
    }
    if (c > 0) {
        if (a + c <= A) dfs(a + c, b, 0); else dfs(A, b, c - (A - a));
        if (b + c <= B) dfs(a, b + c, 0); else dfs(a, B, c - (B - b));
    }
}

int main() {
    ifstream fin(PROBLEM ".in");
    ofstream fout(PROBLEM ".out");

    fin >> A >> B >> C;
    dfs(0, 0, C);
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        fout << res[i];
        if (i < res.size() - 1)
            fout << ' ';
    }
    fout << '\n';

    fin.close();
    fout.close();
    return 0;
}
