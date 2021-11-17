#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0) a[i] = min(a[i], a[i - 1]);
        cout << a[i];
        if (i + 1 < n) cout << ' ';
    }
    cout << '\n';
    return 0;
}
