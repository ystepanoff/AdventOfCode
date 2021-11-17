#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

long long solve(string &s) {
    int n = s.length();
    int curr_hand = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'X') break;
        if (s[i] == 'O') {
            curr_hand = 1;
            break;
        }
    }
    vector<vector<int>> closest(n, vector<int>(2));
    int lastx = -1, lasto = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'X') lastx = i;
        if (s[i] == 'O') lasto = i;
        closest[i][0] = lastx;
        closest[i][1] = lasto;
    }
    long long total = 0;
    long long curr = 0;
    for (int i = 0; i < n; i++) {
        if ((s[i] == 'O' && curr_hand == 0) || (s[i] == 'X' && curr_hand == 1)) {
            curr = (curr + closest[i][curr_hand] + 1) % mod;
            curr_hand = (curr_hand + 1) % 2;
        }
        total = (total + curr) % mod;
    }
    return total;
}


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
        long long g = solve(s);
        cout << "Case #" << _t << ": " << g << '\n';
    }
    return 0;
}
