#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < (1 << n); i++) {
        vector<int> d;
        for (int j = 0, k = i ^ (i >> 1); j < n; j++, k >>= 1)
            d.push_back(k & 1);
        for (int j = d.size() - 1; j >= 0; j--)
            cout << d[j];
        cout << '\n';
    }
    return 0;
}
