#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    a[0] = -1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int c = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != a[i - 1]) {
            if (i > 1) cout << c << ' ' << a[i - 1] << ' ';
            c = 0;
        }
        c++;
    }
    cout << c << ' ' << a[n] << '\n';
    return 0;
}
