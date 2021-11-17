/*
ID: dr.yste1
TASK: preface
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "preface"

vector<int> decimal = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
vector<string> roman = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
string letters = "IVXLCDM";

int main() {
    ifstream fin(PROBLEM ".in");
    ofstream fout(PROBLEM ".out");
    int n;
    fin >> n;
    vector<int> cnt(256, 0);
    for (int i = 1; i <= n; i++) {
        int k = i;
        for (int j = 0; j < decimal.size(); j++) {
            while (k >= decimal[j]) {
                for (char c : roman[j]) cnt[c]++;
                k -= decimal[j];
            }
        }
    }
    for (char c : letters) {
        if (cnt[c] == 0) break;
        fout << c << ' ' << cnt[c] << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}
