/*
ID: dr.yste1
TASK: ariprog
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "ariprog"

int main() {
    ifstream fin(PROBLEM ".in");
    ofstream fout(PROBLEM ".out");

    int n, m;
    fin >> n >> m;
    vector<bool> exists(250 * 250 * 2 + 1, false);
    vector<int> s;
    int mx = 0;
    for (int p = 0; p <= m; p++)
        for (int q = 0; q <= m; q++) {
            int x = p * p + q * q;
            if (!exists[x]) {
                exists[x] = true;
                s.push_back(x);
                if (x > mx)
                    mx = x;
            }
        }
    sort(s.begin(), s.end());
    bool none = true;
    for (int d = 1; d <= mx; d++) {
        for (int b : s) {
            if (b + (n - 1) * d > mx)
                break;
            bool good = true;
            int a = b;
            for (int i = 0; i < n; i++) {
                if (!exists[a]) {
                    good = false;
                    break;
                }
                a += d;
            }
            if (good) {
                fout << b << ' ' << d << '\n';
                none = false;
            }
        }
    }
    if (none)
        fout << "NONE\n";

    fin.close();
    fout.close();
    return 0;
}
