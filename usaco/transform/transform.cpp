/*
ID: dr.yste1
TASK: transform
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

vector<string> rotate(vector<string> &a) {
    vector<string> b = a;
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < a.size(); j++)
            b[j][a.size() - i - 1] = a[i][j];
    return b;
}

bool cmp(vector<string> &a, vector<string> &b) {
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < a.size(); j++)
            if (a[i][j] != b[i][j])
                return false;
    return true;
}

int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    int n;
    fin >> n;
    vector<string> a(n), b(n);
    for (int i = 0; i < n; i++)
        fin >> a[i];
    for (int i = 0; i < n; i++)
        fin >> b[i];
    vector<string> c = a;
    for (int i = 1; i <= 3; i++) {
        c = rotate(c);
        if (cmp(c, b)) {
            fout << i << '\n';
            return 0;
        }
    }
    c = a;
    for (int i = 0; i < n; i++)
        c[i] = string(c[i].rbegin(), c[i].rend());
    if (cmp(c, b)) {
        fout << "4\n";
        return 0;
    }
    for (int i = 1; i <= 3; i++) {
        c = rotate(c);
        if (cmp(c, b)) {
            fout << "5\n";
            return 0;
        }
    }
    if (cmp(a, b)) {
        fout << "6\n";
        return 0;
    }
    fout << "7\n";
    return 0;
}
