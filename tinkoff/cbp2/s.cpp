#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cnt(256, 0);
    auto good = [&]() {
        for (char c = 'a'; c <= 'z'; c++)
            if (cnt[c] > k)
                return false;
        return true;
    };
    int best = 1, bestl = 1;
    int l = 0;
    for (int r = 0; r < n; r++) {
        cnt[s[r]]++;
        while (!good()) {
            cnt[s[l]]--;
            l++;
        }
        if (r - l + 1 > best) {
            best = r - l + 1;
            bestl = l + 1;
        }
    }
    cout << best << ' ' << bestl << '\n';
    return 0;
}
