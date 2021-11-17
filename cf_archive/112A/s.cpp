#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    auto f = [](unsigned char c) {
        return tolower(c);
    };
    while (cin >> s >> t) {
        transform(s.begin(), s.end(), s.begin(), f);
        transform(t.begin(), t.end(), t.begin(), f);
        int r = s.compare(t);
        cout << (r > 0 ? 1 : r < 0 ? -1 : 0) << '\n';
    }
    return 0;
}
