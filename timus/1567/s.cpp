#include <bits/stdc++.h>
using namespace std;

vector<string> btns = {
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqr",
    "stu",
    "vwx",
    "yz",
    ".,!",
    " "
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    getline(cin, s);
    int total = 0;
    for (char c : s) {
        for (string s : btns) {
            auto it = find(s.begin(), s.end(), c);
            if (it != s.end()) total += (it - s.begin()) + 1;
        }
    }
    cout << total << '\n';
    return 0;
}
