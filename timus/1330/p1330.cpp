#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> sums(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        sums[i] = x + sums[i - 1];
    }
    int q;
    cin >> q;
    while (q--) {
        int i, j;
        cin >> i >> j;
        cout << sums[j] - sums[i - 1] << '\n';
    }
    return 0;
}
