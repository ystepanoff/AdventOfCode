#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        int j = min_element(s.begin(), s.end()) - s.begin();
        cout << s[j] << ' ';
        for (int i = 0; i < s.length(); i++) {
            if (i != j) cout << s[i];
        }
        cout << '\n';
    }
    return 0;
}
