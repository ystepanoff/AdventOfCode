#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int,int> cnt;
    int l = 0, k = 0;
    int best = 1;
    for (int r = 0; r < n; r++) {
        cnt[a[r]]++;
        if (cnt[a[r]] == 1)
            k++;
        while (k < r - l + 1) {
            cnt[a[l]]--;
            if (cnt[a[l]] == 0)
                k--;
            l++;
        }
        best = max(best, r - l + 1);
    }
    cout << best << '\n';
    return 0;
}
