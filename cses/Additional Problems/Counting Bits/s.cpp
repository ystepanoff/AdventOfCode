#include <bits/stdc++.h>
using namespace std;

unordered_map<long long,long long> cache;

long long count(long long n) {
    if (!n) return 0;
    if (cache[n]) return cache[n];
    long long k = n >> 1;
    long long r;
    if (n & 1) {
        r = 2 * count(k) + k + 1;
    } else {
        r = count(k) + count(k - 1) + k;
    }
    return cache[n] = r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;
    cout << count(n) << '\n';
    return 0;
}
