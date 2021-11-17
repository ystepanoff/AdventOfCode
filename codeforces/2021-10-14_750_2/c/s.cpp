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
        int best = -1;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            int l = 0, r = n - 1;
            int curr = 0;
            bool bad = false;
            while (l < r) {
                if (s[l] != s[r]) {
                    if (s[l] == ch) l++, curr++;
                    else if (s[r] == ch) r--, curr++;
                    else {
                        bad = true;
                        break;
                    }
                } else {
                    l++, r--;
                }
            }
            if (!bad) {
                if (best == -1 || curr < best) best = curr;
            }
        }
        cout << best << '\n';
    }
    return 0;
}
