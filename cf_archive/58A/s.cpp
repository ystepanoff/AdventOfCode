#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    string t = "hello";
    while (cin >> s) {
        int n = s.length();
        int k = 0;
        for (char c : s)
            if (k < 5 && c == t[k])
                k++;
        cout << (k == 5 ? "YES" : "NO") << '\n';
    }
    return 0;
}
