/*
ID: dr.yste1
TASK: gift1
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int n;
    fin >> n;
    vector<string> f(n);
    for (int i = 0; i < n; i++)
        fin >> f[i];
    unordered_map<string,int> b;
    string s;
    while (fin >> s) {
        int n, k;
        fin >> n >> k;
        if (!k) {
            //b[s] += n;
            continue;
        }
        b[s] -= n;
        b[s] += n % k;
        for (int i = 0; i < k; i++) {
            string t;
            fin >> t;
            b[t] += n / k;
        }
    }
    for (string t : f)
        fout << t << ' ' << b[t] << '\n';
    return 0;
}
