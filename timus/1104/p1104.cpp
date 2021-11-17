#include <bits/stdc++.h>
using namespace std;

string alpha = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int min_k = 2;
    for (char c : s) {
        auto it = find(alpha.begin(), alpha.end(), c);
        min_k = max(min_k, (int)(it - alpha.begin()) + 1);
    }
    for (int k = min_k; k <= 36; k++) {
        int mod = 0;
        for (char c : s) {
            auto it = find(alpha.begin(), alpha.end(), c);
            mod = (mod * k + (int)(it - alpha.begin())) % (k - 1);
        }
        if (!mod) {
            cout << k << '\n';
            return 0;
        }
    }
    cout << "No solution.\n";
    return 0;
}
