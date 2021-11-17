#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while (cin >> s) {
        vector<int> c(256, 0);
        for (char ch : s)
            c[ch]++;
        int t = 0;
        for (int i = 0; i < 256; i++)
            if (c[i])
                t++;
        cout << ((t & 1) ? "IGNORE HIM!" : "CHAT WITH HER!") << '\n';
    }
    return 0;
}
