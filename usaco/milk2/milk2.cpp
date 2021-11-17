/*
ID: dr.yste1
TASK: milk2
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    vector<int> c(1000000, 0);
    int n;
    fin >> n;
    int start = -1, end = -1;
    while (n--) {
        int l, r;
        fin >> l >> r;
        start = start == -1 ? l : min(start, l);
        end = end == -1 ? r : max(end, r);
        for (int i = l; i < r; i++)
            c[i] = 1;
    }
    int besta = 0, bestb = 0, a = 0, b = 0;
    for (int i = start; i < end; i++) {
        if (c[i] == 1) {
            a++;
            b = 0;
        } else {
            a = 0;
            b++;
        }
        besta = max(a, besta);
        bestb = max(b, bestb);
    }
    fout << besta << ' ' << bestb << '\n';
    return 0;
}
