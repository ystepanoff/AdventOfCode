/*
ID: dr.yste1
TASK: sort3
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "sort3"

int main() {
    ifstream fin(PROBLEM ".in");
    ofstream fout(PROBLEM ".out");
    int n;
    fin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        fin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    int total = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i] != b[i] && a[j] != b[j] && a[i] == b[j] && a[j] == b[i]) {
                swap(a[i], a[j]);
                total++;
            }
    int add = 0;
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            add++;
    add /= 3;
    total += 2 * add;
    fout << total << '\n';
    fin.close();
    fout.close();
    return 0;
}
