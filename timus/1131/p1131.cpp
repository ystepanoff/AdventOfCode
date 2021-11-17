#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n, k;
    cin >> n >> k;
    long long total = 0, cnt = 1;
    while (cnt < k && cnt < n) {
        cnt += cnt;
        total++;
    }
    if (cnt < n)
        total += (n - cnt + k - 1) / k;
    cout << total << "\n";
    return 0;
}
