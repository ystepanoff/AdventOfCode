/*
ID: dr.yste1
TASK: crypt1
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "crypt1"

bool check(int n, int x, vector<int> &d) {
    vector<int> a;
    for (; x > 0; x /= 10)
        a.push_back(x % 10);
    for (int c : a)
        if (find(d.begin(), d.end(), c) == d.end())
            return false;
    return a.size() == n;
}

int main() {
    ifstream fin(PROBLEM ".in");
    ofstream fout(PROBLEM ".out");
    int n;
    fin >> n;
    vector<int> digits(n);
    for (int i = 0; i < n; i++)
        fin >> digits[i];
    int total = 0;
    for (int a : digits)
        for (int b : digits)
            for (int c : digits)
                for (int d : digits)
                    for (int e : digits) {
                        int x = a * 100 + b * 10 + c;
                        int y = d * 10 + e;

                        if (check(3, x * e, digits) && check(3, x * d, digits) && check(4, x * y, digits))
                            total++;
                    }
    fout << total << '\n';
    return 0;
}
