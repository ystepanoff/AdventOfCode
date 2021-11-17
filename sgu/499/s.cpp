#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> cnt(1000010, 0);
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        for (int c = 1; c * c <= v; c++)
            if (!(v % c)) {
                cnt[c]++;
                cnt[v / c]++;
            }
    }
    for (int i = 1000000; i >= 1; i--)
        if (cnt[i] >= 2) {
            cout << i << '\n';
            break;
        }
    return 0;
}
