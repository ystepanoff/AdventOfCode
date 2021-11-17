#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int l = 0, r = a.size() - 1;
    int total = 0;
    while (l < r) {
        while (l < r && a[l] + a[r] > x)
            total++, r--;
        if (l < r && a[l] + a[r] <= x)
            total++, l++, r--;
        if (l == r) {
            total++;
            break;
        }
    }
    cout << total << '\n';
    return 0;
}
