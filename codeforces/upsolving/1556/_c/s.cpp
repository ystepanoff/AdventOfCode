#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    long long total = 0;
    for (int l = 0; l < n; l += 2) {
        long long balance = 0;
        long long min_balance = 0;
        for (int r = l + 1; r < n; r++) {
            if (r & 1) {
                if (min_balance < 0) {
                    long long left = max(c[l] + min_balance, 0ll);
                    long long right = max(c[r] - balance, 0ll);
                    total += min(left, right);
                } else {
                    long long left = c[l];
                    long long right = max(c[r] - balance, 0ll);
                    total += min(left, right);
                }
                balance -= c[r];
            } else {
                balance += c[r];
            }
            min_balance = min(min_balance, balance);
        }
    }
    cout << total << '\n';
    return 0;
}
