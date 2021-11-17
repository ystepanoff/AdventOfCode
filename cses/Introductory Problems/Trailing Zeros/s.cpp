#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int r = 0;
    for (; n > 0; n /= 5)
        r += n / 5;
    cout << r << '\n';
    return 0;
}
