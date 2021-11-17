#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while (cin >> s) {
        bool y = false;
        for (char c : s)
            y |= (c == 'H' || c == 'Q' || c == '9');
        cout << (y ? "YES" : "NO") << '\n';
    }
    return 0;
}
