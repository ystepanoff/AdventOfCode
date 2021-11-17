#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    for (int _t = 1; _t <= tt; _t++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int best = -1;
        for (int t = 0; t < 2; t++) {
            int curr = 0, curr_hand = t;
            for (int i = 0; i < n; i++) {
                if ((s[i] == 'O' && curr_hand == 0) || (s[i] == 'X' && curr_hand == 1)) {
                    curr_hand = (curr_hand + 1) % 2;
                    curr++;
                }
            }
            if (best == -1 || curr < best) {
                best = curr;
            }
        }
        cout << "Case #" << _t << ": " << best << '\n';
    }
    return 0;
}
