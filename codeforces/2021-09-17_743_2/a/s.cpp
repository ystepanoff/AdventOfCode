#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int total = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                total += s[i] - '0';
                if (i < n - 1) total++;
            }
        }
        cout << total << '\n';
    }
    return 0;
}
