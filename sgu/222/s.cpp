#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n, k;
    cin >> n >> k;
    long long r = 1;
    for (long long i = 0; i < k; i++)
        r *= (n - i) * (n - i);
    for (long long i = 2; i <= k; i++)
        r /= i;
    cout << r << '\n';
    return 0;
}
