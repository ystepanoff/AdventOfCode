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
    int besti = 1;
    for (int i = 2; i < n - 1; i++) {
        if (a[i - 1] + a[i] + a[i + 1] > a[besti - 1] + a[besti] + a[besti + 1]) {
            besti = i;
        }
    }
    cout << a[besti - 1] + a[besti] + a[besti + 1] << ' ' << besti + 1 << '\n';
    return 0;
}
