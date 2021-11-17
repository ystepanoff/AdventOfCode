#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, h;
    while (cin >> n >> h) {
        int r = 0;
        while (n--) {
            int v;
            cin >> v;
            r++;
            if (v > h)
                r++;
        }
        cout << r << '\n';
    }
    return 0;
}
