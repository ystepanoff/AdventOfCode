#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int cnt = 0;
    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a + b + c > 1)
            cnt++;
    }
    cout << cnt << '\n';
    return 0;
}
