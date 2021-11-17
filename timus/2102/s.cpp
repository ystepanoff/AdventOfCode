#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;
    int total = 0;
    for (long long c = 2; c * c * c * c <= n; c++) {
        for (; !(n % (c * c)); n /= c * c) total += 2;
    }
    if (total == 0) {
        cout << "No\n";
        return 0;
    }
    for (long long c = 2; c * c <= n; c++) {
        for (; !(n % c); n /= c) total++;
    }
    if (n > 1) total++;
    cout << (total == 20 ? "Yes" : "No") << "\n";
    return 0;
}
