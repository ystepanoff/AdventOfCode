/*
ID: dr.yste1
TASK: skidesign
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "skidesign"

int main() {
    ifstream fin(PROBLEM ".in");
    ofstream fout(PROBLEM ".out");

    int n;
    fin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        fin >> a[i];
    int best = -1;
    for (int l = 0; l <= 83; l++) {
        int curr = 0;
        for (int x : a) {
            if (x < l) curr += (l - x) * (l - x);
            if (x > l + 17) curr += (x - l - 17) * (x - l - 17);
        }
        if (best == -1 || curr < best)
            best = curr;
    }
    fout << best << '\n';

    fin.close();
    fout.close();
    return 0;
}
