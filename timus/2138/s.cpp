#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string type;
    cin >> type;
    long long v;
    cin >> v;
    vector<long long> d;
    for (int i = 0; i < 4; i++) {
        d.push_back(v % (1 << 8));
        v >>= 8;
    }
    long long r = 0;
    for (long long x : d) {
        r = (r << 8) + x;
    }
    cout << r << '\n';
    return 0;
}
