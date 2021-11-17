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
        int s = accumulate(a.begin(), a.end(), 0);
        if (s % n) {
            cout << "-1\n";
            continue;
        } 
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > s / n) k++;
        } 
        cout << k << '\n';
    }
    return 0;
}
