#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    int b = 0, c = 0;
    for (int i = 0; i < 4; i++)
        if (s[i] == t[i]) {
            b++;
        } else {
            if (find(s.begin(), s.end(), t[i]) != s.end())
                c++;
        }
    cout << b << ' ' << c << '\n';
    return 0;
}
