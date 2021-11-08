#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(k);
        for (int i = 0;  i < k; i++) {
            cin >> a[i];
        }
        int total = 0, cat = 0;
        sort(a.rbegin(), a.rend());
        for (int x : a) {
            if (x > cat) {
                cat += n - x;
                total++;
            }
        }
        cout << total << '\n';
    }
    return 0;
}
