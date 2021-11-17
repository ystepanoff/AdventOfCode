#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    while (cin >> s >> t) {
        cout << (!s.compare(string(t.rbegin(), t.rend())) ? "YES" : "NO") << '\n';
    }
    return 0;
}
