#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int h, w, n;
    cin >> h >> w >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int total = 1, curr = 0;
    for (int i = 0; i < n; i++) {
        if (curr + a[i].length() + (int)(curr != 0) > w) {
            total++;
            curr = 0;
        }
        curr += a[i].length() + (int)(curr != 0);
    }
    cout << ((total + h - 1) / h) << '\n';
    return 0;
}
