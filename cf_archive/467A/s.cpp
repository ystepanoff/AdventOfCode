#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        int total = 0;
        while (n--) {
            int p, q;
            cin >> p >> q;
            total += q - p > 1;
        }
        cout << total << '\n';
    }
    return 0;
}
