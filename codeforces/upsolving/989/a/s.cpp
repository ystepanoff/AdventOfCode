#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    vector<int> cnt(3, 0);
    for (int i = 1; i < s.length() - 1; i++) {
        cnt[0] = cnt[1] = cnt[2] = 0;
        cnt[s[i - 1] - 'A']++;
        cnt[s[i] - 'A']++;
        cnt[s[i + 1] - 'A']++;
        if (cnt[0] == 1 && cnt[1] == 1 && cnt[2] == 1) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}
