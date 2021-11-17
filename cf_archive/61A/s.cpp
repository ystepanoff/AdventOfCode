#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    while (cin >> s >> t) {
        for (int i = 0; i < s.length(); i++)
            cout << ((s[i] - '0') ^ (t[i] - '0'));
        cout << '\n';
    }
    return 0;
}
