#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k, n;
    cin >> k >> n;
    int s = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    bool yes = false;
    for (int i = 0; i < n; i++) {
        yes |= s - a[i] >= k;
    }
    cout << (yes ? "YES" : "NO") << '\n';
    return 0;
}
