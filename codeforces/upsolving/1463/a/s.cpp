#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b, c;
        cin >> a >> b >> c;
        int s = a + b + c;
        if (s % 9) {
            cout << "No\n";
        } else {
            s /= 9;
            cout << (min(a, min(b, c)) >= s ? "Yes" : "No") << '\n';
        }
    }
    return 0;
}
