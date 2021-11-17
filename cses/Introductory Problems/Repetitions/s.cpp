#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int best = 1, curr = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) curr++; else curr = 1;
        best = max(best, curr);
    }
    cout << best << '\n';
    return 0;
}
