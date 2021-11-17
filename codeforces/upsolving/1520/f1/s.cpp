#include <bits/stdc++.h>
using namespace std;

int ask(int l, int r) {
    cout << "? " << l << ' ' << r << '\n';
    cout.flush();
    int s;
    cin >> s ;
    return r - l + 1 - s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, t, k;
    cin >> n >> t >> k;
    int l = 1, r = n;
    while (r > l) {
        int m = (l + r) >> 1;
        int x = ask(l, m);
        if (x >= k) {
            r = m; 
        } else {
            l = m + 1;
            k -= x;
        }
    }
    cout << "! " << l << '\n';
    cout.flush();
    return 0;
}
