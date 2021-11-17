/*
ID: dr.yste1
TASK: pprime
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "pprime"

set<int> pal;

bool is_prime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (!(n & 1)) return false;
    for (int c = 3; c * c <= n; c += 2)
        if (!(n % c))
            return false;
    return true;
}

void gen(string s) {
    if (s.size() > 8)
        return;
    if (s.size() > 0) {
        int p = stoi(s);
        if (is_prime(p))
            pal.insert(p);
    }
    for (char c = '0'; c <= '9'; c++)
        gen(c + s + c);
}

int main() {
    ifstream fin(PROBLEM ".in");
    ofstream fout(PROBLEM ".out");
    gen("");
    for (char c = '0'; c <= '9'; c++)
        gen({ c });
    int a, b;
    fin >> a >> b;
    for (int p : pal)
        if (p >= a && p <= b)
            fout << p << '\n';
    fin.close();
    fout.close();
    return 0;
}
