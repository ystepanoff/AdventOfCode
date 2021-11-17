#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> xors(300100);
    xors[0] = 0;
    for (int i = 1; i < xors.size(); i++)
        xors[i] = i ^ xors[i - 1];
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b;
        cin >> a >> b;
        // a -- mex => arr = [0, 1, ..., a - 1]
        // b -- xor
        // x = xor(0, 1, ..., a - 1)
        // 1. b == x => a
        // 2. b != x && x ^ b != a => a + 1
        // 3. b != x && x ^ b == a => a + 2
        int x = xors[a - 1];
        if (b == x) {
            cout << a << '\n';
        } else {
            if ((b ^ x) == a) {
                cout << a + 2 << '\n';
            } else {
                cout << a + 1 << '\n';
            }
        }
    }
    return 0;
}
