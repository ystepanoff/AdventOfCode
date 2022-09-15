#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        long long n, s;
        cin >> n >> s;
        cout << (s / (n * n)) << '\n';
    }
    return 0;
}
