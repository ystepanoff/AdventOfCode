#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;
    long long s = n * (n + 1) / 2;
    while (n-- > 1) {
        long long x;
        cin >> x;
        s -= x;
    }
    cout << s << '\n';
    return 0;
}
