#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        bool e = true;
        while (n--) {
            int x;
            cin >> x;
            e &= !x;
        }
        cout << (e ? "easy" : "hard") << '\n';
    }
    return 0;
}
