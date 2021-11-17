/*
ID: dr.yste1
TASK: palsquare
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "palsquare"

string alpha = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string convert(int n, int b) {
    string r = "";
    for (; n > 0; n /= b)
        r += alpha[n % b];
    return string(r.rbegin(), r.rend());
}

int main() {
    ifstream fin(PROBLEM ".in");
    ofstream fout(PROBLEM ".out");
    int b;
    fin >> b;
    for (int i = 1; i <= 300; i++) {
        string r = convert(i * i, b);
        if (!r.compare(string(r.rbegin(), r.rend()))) {
            fout << convert(i, b) << ' ' << r << '\n';
        }
    }
    return 0;
}
