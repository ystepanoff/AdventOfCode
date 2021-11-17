/*
ID: dr.yste1
TASK: fracdec
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "fracdec"

map<pair<int,int>,int> seen;
vector<int> result;
int pos = -1, i = 0;


void divide(int a, int b) {
    if (!a) return;
    if (seen.find(make_pair(a, b)) != seen.end()) {
        pos = seen[make_pair(a, b)];
        return;
    }
    seen[make_pair(a, b)] = i++;
    result.push_back(a / b);
    divide((a % b) * 10, b);
}

int main() {
    ifstream fin(PROBLEM ".in");
    ofstream fout(PROBLEM ".out");
    int a, b;
    fin >> a >> b;
    if (a % b == 0) {
        fout << a / b << ".0\n";
        return 0;
    }
    divide(a, b);
    string r = to_string(result[0]) + '.';
    if (pos == -1) pos = result.size();
    for (int i = 1; i < pos; i++)
        r += to_string(result[i]);
    if (pos < result.size()) {
        r += '(';
        for (int i = pos; i < result.size(); i++)
            r += to_string(result[i]);
        r += ')';
    }
    for (int i = 0; i < r.length(); i++) {
        fout << r[i];
        if ((i + 1) % 76 == 0) fout << '\n';
    }
    if (r.length() % 76) fout << '\n';
    fin.close();
    fout.close();
    return 0;
}
