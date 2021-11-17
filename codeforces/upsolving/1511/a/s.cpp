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
        vector<int> a(n), s1(2, 0), s2(2, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                s1[0]++;
            } else if (a[i] == 2) {
                s2[1]++;
            } else {
                s1[0]++;
            }
        }
        cout << s1[0] << '\n';
    }
    return 0;
}
