#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = "";
    for (char c : s) {
        if (c == '<' || c == '>') t += c;
    }
    string s1 = "", s2 = "", s3 = "", s4 = "";
    for (int i = 0; i < n / 2; i++) {
        s1 += '<';
        s2 += '>';
    }
    for (int i = 0; i < n / 2; i++) {
        s1 += '>';
        s2 += '<';
    }
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            s3 += '>';
            s4 += '<';
        } else {
            s3 += '<';
            s4 += '>'; 
        }
    }
    int best = n;
    for (string st : {s1, s2, s3, s4}) {
        int diff = 0;
        for (int i = 0; i < n; i++)
            diff += (int)(t[i] != st[i]);
        best = min(best, diff);
    }
    cout << best << '\n';
    return 0;
}
