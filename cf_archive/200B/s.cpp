#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        int s = 0;
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            s += v;
        }
        cout << (s * 1.0 / n) << '\n';
    }
    return 0;
}
