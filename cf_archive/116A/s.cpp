#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int curr = 0, best = 0;
    while (n--) {
        int a, b;
        cin >> a >> b;
        curr += (b - a);
        best = max(curr, best);
    }
    cout << best << '\n';
    return 0;
}
