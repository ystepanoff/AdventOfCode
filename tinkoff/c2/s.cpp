#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    string t = string(n - 1, ' ');
    int l = 0, r = n - 2;
    for (int i = 0; i < n - 1; i++) {
        if (i & 1) {
            t[r--] = s[i];
        } else {
            t[l++] = s[i];
        }
    }
    cout << t << '\n';
    return 0;
}
