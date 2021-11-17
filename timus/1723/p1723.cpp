#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    vector<int> cnt(256, 0);
    for (char c : s)
        cnt[c]++;
    int best = *max_element(cnt.begin(), cnt.end());
    for (char c : s)
        if (cnt[c] == best) {
            cout << c << '\n';
            break;
        }
    return 0;
}
