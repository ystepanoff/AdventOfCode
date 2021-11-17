#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    string w = "aoyeuiAOYEUI";
    while (cin >> s) {
        for (char c : s)
            if (find(w.begin(), w.end(), c) == w.end()) {
                c = tolower(c);
                cout << '.' << c;
            }
        cout << '\n';
    }
    return 0;
}
