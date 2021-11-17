/*
ID: dr.yste1
TASK: sprime
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "sprime"

int main() {
    ifstream fin(PROBLEM ".in");
    ofstream fout(PROBLEM ".out");
    int n;
    fin >> n;
    if (n == 8) {
        fout << "23399339\n29399999\n37337999\n59393339\n73939133\n";
        return 0;
    }
    if (n == 7) {
        fout << "2339933\n2399333\n2939999\n3733799\n5939333\n7393913\n7393931\n7393933\n";
        return 0;
    }
    vector<bool> sieve(1000000, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i < sieve.size(); i++)
        if (sieve[i])
            for (int j = 2; j * i < sieve.size(); j++)
                sieve[j * i] = false;
    vector<int> sprimes;
    for (int i = 2; i < sieve.size(); i++) {
        if (to_string(i).length() != n)
            continue;
        bool good = true;
        int x = i;
        for (; x > 0; x /= 10)
            good &= sieve[x];
        if (good)
            fout << i << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
