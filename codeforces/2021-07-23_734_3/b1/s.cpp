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
        vector<int> cnt(256, 0);
        for (char c : s)
            cnt[c]++;
        int t = 0, k = 0;
        for (int i = 0; i < 256; i++)
            if (cnt[i] == 1) {
                k++;
            } else if (cnt[i] > 1) {
                t++;
            }
        t += k / 2;
        cout << t << '\n';
    }
    return 0;
}
