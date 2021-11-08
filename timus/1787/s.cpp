#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k, n;
    cin >> k >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int total = 0;
    for (int x : a) {
        total += x;
        total = max(0, total - k);
    }
    cout << total << '\n';
    return 0;
}
