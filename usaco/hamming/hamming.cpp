/*
ID: dr.yste1
TASK: hamming
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "hamming"

int main() {
    ifstream fin(PROBLEM ".in");
    ofstream fout(PROBLEM ".out");
    int n, b, d;
    fin >> n >> b >> d;
    vector<int> a = { 0 };
    for (int mask = 1; mask < (1 << b); mask++) {
        bool good = true;
        for (int x : a) {
            int cnt = 0;
            for (int i = 0; i < b; i++) {
                if ((bool)(mask & (1 << i)) != (bool)(x & (1 << i))) cnt++;
            }
            good &= cnt >= d;
        }
        if (good) a.push_back(mask);
    }
    for (int i = 0; i < n; i++) {
        fout << a[i];
        if ((i + 1) % 10 == 0) {
            fout << '\n';
        } else if (i + 1 < n) {
            fout << ' ';
        }
    }
    if (n % 10 != 0) fout << '\n';
    fin.close();
    fout.close();
    return 0;
}
