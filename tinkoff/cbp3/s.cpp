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
    }
    vector<int> b(n, 1);
    for (int i = n - 2; i >= 0; i--) 
        b[i] += a[i + 1] < a[i] ? b[i + 1] : 0;
    int k = 0, best = 0;
    for (int i = 0; i < n; i++) {
        if (k == 0) {
            k = b[i];
            best = b[i];
        }
        k--;
        cout << best;
        if (i + 1 < n) cout << ' ';
    }
    cout << '\n';
    return 0;
}
