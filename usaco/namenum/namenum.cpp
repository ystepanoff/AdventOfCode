/*
ID: dr.yste1
TASK: namenum
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "namenum"

vector<int> vals = {
    2, 2, 2,
    3, 3, 3,
    4, 4, 4,
    5, 5, 5,
    6, 6, 6,
    7, 7, 7,
    8, 8, 8,
    9, 9, 9
};

int main() {
    ifstream fin(PROBLEM ".in");
    ofstream fout(PROBLEM ".out");

    ifstream dict("dict.txt");
    map<string,vector<string>> val;
    string s;
    while (dict >> s) {
        string t = "";
        for (char c : s) {
            int idx = c - 'A';
            if (c > 'Q')
                idx--;
            t += (char)(vals[idx] + '0');
        }
        val[t].push_back(s);
    }

    fin >> s;
    if (val.find(s) != val.end())
        for (string t : val[s])
            fout << t << "\n";
    else
        fout << "NONE\n";

    return 0;
}
