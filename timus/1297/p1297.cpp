#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int bestl = 0, bestr = 0;
    for (int t = 0; t < 2; t++)
        for (int i = 0; i + t < n; i++)
            for (int l = i, r = i + t; l >= 0 && r < n; l--, r++) {
                if (s[l] != s[r]) break;
                if (r - l > bestr - bestl)
                    bestl = l, bestr = r;
            }
    cout << s.substr(bestl, bestr - bestl + 1) << '\n';
    return 0;
}
