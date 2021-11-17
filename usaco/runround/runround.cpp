/*
ID: dr.yste1
TASK: runround
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "runround"

bool runround(long long m) {
    vector<int> d;
    set<int> sd;
    for (; m > 0; m /= 10) {
        d.push_back(m % 10);
        if (d.back() == 0) return false;
        sd.insert(d.back());
    }
    if (sd.size() != d.size()) return false;
    reverse(d.begin(), d.end());
    sd.clear();
    int curr = 0;
    while (sd.find(d[curr]) == sd.end()) {
        sd.insert(d[curr]);
        curr = (curr + d[curr]) % d.size();
    }
    return sd.size() == d.size() && curr == 0;
}

int main() {
    ifstream fin(PROBLEM ".in");
    ofstream fout(PROBLEM ".out");
    long long m;
    fin >> m;
    m++;
    while (!runround(m)) m++;
    fout << m << '\n';
    fin.close();
    fout.close();
    return 0;
}
