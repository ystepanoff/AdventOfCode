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
    int mx = *max_element(a.begin(), a.end());
    if (mx < 0) {
        cout << mx << '\n';
        return 0;
    }
    long long best = 0, curr = 0;
    for (int i = 0; i < n; i++) {
        curr += a[i];
        if (curr < 0)
            curr = 0;
        best = max(best, curr);
    }
    cout << best << '\n';
    return 0;
}
