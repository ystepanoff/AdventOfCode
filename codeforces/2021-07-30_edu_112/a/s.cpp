#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        long long n;
        cin >> n;
        if (n & 1)
            n++;
        cout << max(15LL, (n / 2) * 5) << '\n';
    }
    return 0;
}
