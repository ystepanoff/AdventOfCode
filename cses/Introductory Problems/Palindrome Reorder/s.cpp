#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> cnt(256, 0);
    for (char c : s) cnt[c]++;
    int odd = 0;
    char odd_c = 0;
    for (char c = 'A'; c <= 'Z'; c++)
        if (cnt[c] & 1) {
            odd += 1;
            odd_c = c;
        }
    if (odd > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    if (odd_c) cnt[odd_c] -= 1;
    for (char c = 'A'; c <= 'Z'; c++)
        for (int i = 0; i < cnt[c] / 2; i++)
            cout << c;
    if (odd_c) cout << odd_c;
    for (char c = 'Z'; c >= 'A'; c--)
        for (int i = 0; i < cnt[c] / 2; i++)
            cout << c;
    cout << '\n';
    return 0;
}
