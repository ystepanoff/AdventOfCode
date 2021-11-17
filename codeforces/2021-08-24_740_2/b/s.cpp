#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b;
        cin >> a >> b;
        int n = a + b;
        set<int> s;
        int cA = (n >> 1) + (n & 1);
        int cB = n - cA;
        for (int t = 0; t < 2; t++) {
            for (int i = 0; i <= cA; i++) {
                // (a - i) -- A's breaks
                // (cA - i) -- B'c breaks
                int ab = a - i, bb = cA - i;
                if (ab >= 0 && bb >= 0 && ab <= a && bb <= b && b - cA + i >= 0 && b - cA + i <= b)
                    s.insert(a + cA - 2 * i);
            }
            for (int i = 0; i <= cB; i++) {
                int ab = cB - i, bb = b - i;
                if (ab >= 0 && bb >= 0 && ab <= a && bb <= b && a - cB + i >= 0 && a - cB + i <= b)
                    s.insert(b + cB - 2 * i);
            }
            swap(cA, cB);
        }
        cout << s.size() << '\n';
        for (int x : s)
            cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
