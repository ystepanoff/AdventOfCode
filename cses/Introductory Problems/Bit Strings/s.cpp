#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long p = 1;
    while (n--) {
        p = (p * 2) % MOD;
    }
    cout << p << '\n';
    return 0;
}
