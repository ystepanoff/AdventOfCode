#include <bits/stdc++.h>
using namespace std;

const long long N = 1e16;

bool check(long long x, long long y) {
    return x * x + x * y + 41 * y * y <= N;
}

int main() {
    long long L = (long long)sqrt(4.0 * N / 163);
    long long total = 0;
    for (long long y = -L; y <= L; y++) {
        long long s = (long long)sqrt(4 * N - 163 * y * y);
        long long l = (-s - y) / 2;
        long long r = (s - y) / 2;
        total += r - l + 1;
        if (!check(l, y)) total--;
        if (!check(r, y)) total--;
    }
    cout << total - 1 << '\n';
    return 0;
}
