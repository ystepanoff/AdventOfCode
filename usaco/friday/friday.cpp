/*
ID: dr.yste1
TASK: friday
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

bool leap(int y) {
    return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
}

int md[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int n; 
    fin >> n;
    int d = 0, m = 0;
    int wd = 2;
    vector<int> c(7, 0);
    for (int y = 1900; y < 1900 + n; y++) {
        if (leap(y))
            md[1] = 29;
        else
            md[1] = 28;
        while (m < 12) {
            if (d == 12)
                c[wd]++;
            d++;
            wd = (wd + 1) % 7;
            if (d == md[m]) {
                d = 0;
                m++;
            }
        }
        m = 0;
        d = 0;
    }
    for (int i = 0; i < 7; i++) {
        fout << c[i];
        if (i != 6)
            fout << ' ';
    }
    fout << '\n';
    return 0;
}
