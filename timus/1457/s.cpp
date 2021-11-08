#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int total = 0;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        total += v;
    }
    cout << fixed << setprecision(6);
    cout << total * 1.0 / n << '\n';
    return 0;
}
