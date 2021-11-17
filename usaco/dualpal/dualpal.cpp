/*
ID: dr.yste1
TASK: dualpal
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "dualpal"

string convert(int n, int b) {
    string r = "";
    for (; n > 0; n /= b)
        r += (char)(n % b + '0');
    return string(r.rbegin(), r.rend());
}

int main() {
    ifstream fin(PROBLEM ".in");
    ofstream fout(PROBLEM ".out");
    int n, s;
    fin >> n >> s;
    for (int i = s + 1; ; i++) {
        int c = 0;
        for (int b = 2; b <= 10; b++) {
            string t = convert(i, b);
            if (!t.compare(string(t.rbegin(), t.rend())))
                c++;
        }
        if (c >= 2) {
            fout << i << '\n';
            n--;
        }
        if (!n)
            break;
    }
    return 0;
}
