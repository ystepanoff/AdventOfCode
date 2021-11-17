/*
ID: dr.yste1
TASK: ride
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

int f(string &s) {
    int r = 1;
    for (char c : s)
        r *= c - 'A' + 1;
    return r;
}

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string s, t;
    while (fin >> s >> t) {
        fout << (f(s) % 47 == f(t) % 47 ? "GO" : "STAY") << '\n';
    }
    return 0;
}
