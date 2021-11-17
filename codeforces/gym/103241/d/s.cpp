#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int best = 0;
    for (char c = 'A'; c <= 'C'; c++) {
        int curr = 0;
        vector<int> cnt(3, 0);
        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'A']++;
            if (c == 'A' && cnt[0] >= cnt[1] && cnt[0] >= cnt[2]) curr++;
            if (c == 'B' && cnt[1] >= cnt[0] && cnt[1] >= cnt[2]) curr++;
            if (c == 'C' && cnt[2] >= cnt[0] && cnt[2] >= cnt[1]) curr++;
        }
        best = max(best, curr);
    }
    cout << best << '\n';
    return 0;
}
