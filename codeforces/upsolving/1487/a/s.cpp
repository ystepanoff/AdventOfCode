#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int c = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[0]) c++;
        }
        cout << c << '\n';
    }
    return 0;
}
