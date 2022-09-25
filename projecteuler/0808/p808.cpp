#include <bits/stdc++.h>
using namespace std;

const long long LIMIT = 200000000;

long long rev(long long n) {
    long long r = 0;
    for (; n > 0; n /= 10) {
        r = r * 10 + (n % 10);
    }
    return r;
}

int main() {
    set<long long> psq;
    vector<char> sieve(LIMIT, 1);
    for (long long i = 2; i < LIMIT; i++) {
        if (sieve[i]) {
            psq.insert(i * i);
            for (int j = 2; j * i < LIMIT; j++) {
                sieve[j * i] = 0;
            }
        }
    }
    int c = 0;
    long long s = 0;
    for (long long n : psq) {
        long long m = rev(n);
        if (n != m && psq.find(m) != psq.end()) {
            c++;
            if (c > 50) break;
            s += n;
        }
    }
    cout << s << '\n';
    return 0; 
}
