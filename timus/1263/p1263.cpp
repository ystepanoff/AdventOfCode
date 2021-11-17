#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> c(n + 1, 0);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        c[x]++;
    }
    cout << fixed << setprecision(2);
    for (int i = 1; i <= n; i++)
        cout << c[i] * 100.0 / k << "%\n";
    return 0;
}
