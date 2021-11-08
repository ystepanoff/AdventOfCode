#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s, t;
        cin >> s >> t;
        int total = 0, curr = -1;
        for (char c : t) {
            auto it = find(s.begin(), s.end(), c);
            if (curr != -1) {
                total += abs((it - s.begin()) - curr);
            }
            curr = it - s.begin();
        }
        cout << total << '\n';
    }
    return 0;
}
