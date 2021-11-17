/*
ID: dr.yste1
TASK: zerosum
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "zerosum"

vector<string> result;

void gen(int n, int i, string expr) {
    if (i == n) {
        int value = 0, curr = 0, sign = 1;
        for (int i = 0; i < expr.length(); i++) {
            if (expr[i] >= '0' && expr[i] <= '9') {
                curr = curr * 10 + expr[i] - '0';
            } else if (expr[i] != ' ') {
                value += sign * curr;
                curr = 0;
                sign = expr[i] == '+' ? 1 : -1;
            }
        }
        if (value + sign * curr == 0) {
            result.push_back(expr);
        }
        return;
    }
    gen(n, i + 1, expr + ' ' + to_string(i));
    gen(n, i + 1, expr + '+' + to_string(i));
    gen(n, i + 1, expr + '-' + to_string(i));
}

int main() {
    ifstream fin(PROBLEM ".in");
    ofstream fout(PROBLEM ".out");
    int n;
    fin >> n;
    gen(n + 1, 2, "1");
    for (string &s : result) {
        fout << s << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}
